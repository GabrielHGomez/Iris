#pragma once

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <string>

template<typename T>
class SharedMemory{
public:
  SharedMemory(std::string& name, bool create = false){
    if(create){
	//create shared memory
    }
    else{
	//create reader I think open_only is a possiblity
    }
  }

  ~SharedMemory() = default;

  void write(){

  }
  // I will need to add read and write function
  void read(){

  }

  std::string& name() {return _name;}

private:
  std::string _name;
  boost::interprocess::shared_memory_object _shm;
  boost::interprocess::mapped_region _mapped_region;
  bool _owner = false;

};



