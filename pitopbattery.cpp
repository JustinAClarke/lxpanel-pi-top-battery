/**
*    pi-top battery Status Class
*    Copyright (C) 2017 Justin Fuhrmeister-Clarke justin@fuhrmeister-clarke.com
*
*    This program is free software; you can redistribute it and/or modify it under the terms of the GNU General      Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
**/

#include "pitopbattery.h"
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <ctime>
#include <wiringPiI2C.h>

class pitopbattery{

  
  //Constructor
  pitopbattery::pitopbattery(){
    this->p_i2c_handle = -1;
    this->p_i2c_handle = wiringPiI2CSetup(0x0b);
//     wiringPiI2CReadReg8(p_i2c_handle, loc);
    this->p_current = -1;
    this->p_charge_time = -1;
    this->p_discharge_time = -1;
    this->p_percent = -1;
    
    this->p_percent = wiringPiI2CReadReg8(p_i2c_handle, 0x0d);
    this->p_current = wiringPiI2CReadReg8(p_i2c_handle, 0x0A);
    if (this->p_current > 32767)                   // status is signed 16 bit word
        this->p_current -= 65536;
    this->p_charge_time = wiringPiI2CReadReg8(p_i2c_handle, 0x13);
    this->p_discharge_time = wiringPiI2CReadReg8(p_i2c_handle, 0x12);
    
  }
  
  //Destructor
  pitopbattery::~pitopbattery(){
    this->p_i2c_handle = -1;
    this->p_current = -1;
    this->p_charge_time = -1;
    this->p_discharge_time = -1;
    this->p_percent = -1;
  }
  
  //Returns the current battery capacity
  int pitopbattery::capacity(){  
    return this->p_percent;
  }
  
  //Returns if currently charging
  bool pitopbattery::isCharging(){
    if(this->p_current > 0)
      return true;
    else
      return false;
  }

  //Returns the current current usage
  int pitopbattery::current(){
    return this->p_current;
  }
  
  //Returns the remaining time
  int pitopbattery::remaining_time(){
    if(isCharging())
      return this->p_charge_time;
    else
      return this->p_discharge_time;
  }
  
}