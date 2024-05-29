#include <iostream>
#include <string>
#include "libsocket/exception.hpp"
#include "libsocket/inetclientstream.hpp"
#include "achr_bridge_cpp/achr_bridge.hpp"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <atomic>

#define _EXIT_          6
#define _RESTART_       5
#define _RECORD_        4
#define _IDLE_          3
#define _SEARCH_        2
#define _CALIBRATE_GPS_ 1



std::atomic<bool> keyPress_;
std::atomic<bool> exit_;

void printMenu()
{
  erase();
  printw("*********************   ACHR Control Interface    *****************************\n\n");
  printw("[1] Calibrate GPS\n[2] Search\n[3] Idle\n[4]  Record\n[5] Restart\n[6] Exit\n");
  printw("*********************   ACHR Control Interface    *****************************\n\n");
  refresh();
}


void readSelection(std::shared_ptr<achr_bridge::achr_control> node)
{
  refresh();
  char inp[1];
  inp[0] = getch();
  flushinp();
  erase();
  int sel = std::atoi(inp);
  refresh();
  keyPress_.store(false);

  switch (sel)
  {
  case _CALIBRATE_GPS_:
    /* code */
    break;
  
  case _SEARCH_:

    node->Search();

    break;

  case _IDLE_:

    node->Idle();

  case _RECORD_:

    break;

  case _RESTART_:
    node->Restart();
    break;

  case _EXIT_:  
    exit_.store(true);
    break;
  
  default:

    erase();
    printw("INVALID MENU OPTION!\n");
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(500ms);
    printMenu();
    readSelection(node);
    break;
  }



}


void printStatus(std::shared_ptr<achr_bridge::achr_control> node)
{

  std::map<std::string,std::string> status_map = node->getStatus();


  erase();
  printw("********************************************************\n");
  
  for(auto const& entry : status_map)
  {
    printw("%s  : %s  \n",entry.first.c_str(),entry.second.c_str());
  }
  
  refresh();

}


void keyBoardThread()
{
  using namespace std::chrono_literals;

  while(!exit_.load())
  {
    if(!keyPress_.load())
    {
      while(!getch())
      {
        std::this_thread::sleep_for(100ms);
      
      }

      keyPress_.store(true);
    }
    std::this_thread::sleep_for(100ms);
  }

}

void menuThread(std::shared_ptr<achr_bridge::achr_control> node)
{

  initscr();
  erase();
  refresh();

  std::thread thread(&keyBoardThread);
  using namespace std::chrono_literals;
  while(rclcpp::ok() && !exit_.load())
  {
    if(keyPress_.load())
    {
      printMenu();
      readSelection(node);
    }
    else
    {
      printStatus(node);
    }

  }

  endwin();

  exit_.store(true);

  thread.join();

  
  //node->Disconnect();
  

  // Disconnect!

}



int main(int argc, char** argv) {

    rclcpp::init(argc,argv);
    

    std::string host = "10.223.100.75";
    std::string port = "7002";
    std::string answer;

    auto node = std::make_shared<achr_bridge::achr_control>();

    node->setHost(host,port);
    if(node->Connect())
    {
      menuThread(node);
    }

    //node->Restart();
    
    return 0;
}