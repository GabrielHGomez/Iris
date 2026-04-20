#pragma once

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <string>
#include <cstring>

template<typename T>
class SharedMemory{
public:
  SharedMemory(std::string name, bool create = false): _name(name), _owner(create){
    if(create){
	//create shared memory
      _shm = boost::interprocess::shared_memory_object{boost::interprocess::create_only, _name.c_str(), boost::interprocess::read_write};
      _shm.truncate(sizeof(T));
    }
    else{
      //create reader I think open_only is a possiblity
      _shm = boost::interprocess::shared_memory_object{boost::interprocess::open_only, name.c_str(), boost::interprocess::read_write};
    }
    _mapped_region = boost::interprocess::mapped_region{_shm, boost::interprocess::read_write};
  }

  ~SharedMemory(){
    if(_owner){
      boost::interprocess::shared_memory_object::remove(_name.c_str());
    }
  }

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

