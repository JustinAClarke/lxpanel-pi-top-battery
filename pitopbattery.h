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


class pitopbattery{
  int p_i2c_handle;
  int p_current;
  int p_charge_time;
  int p_discharge_time;
  int p_percent;
  

  //Constructor
  pitopbattery(){
  }
  
  //Destructor
  ~pitopbattery(){
  }
  
  //Returns the current battery capacity
  int capacity(){  
  }
  
  //Returns if currently charging
  bool isCharging(){
  }

  //Returns the current current usage
  int current(){
  }
  
  //Returns the remaining time
  int remaining_time(){
  }
  
  
}