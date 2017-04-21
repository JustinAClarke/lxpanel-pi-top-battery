/**
*    LXPanel pi-top battery Status
*    Copyright (C) 2017 Justin Fuhrmeister-Clarke justin@fuhrmeister-clarke.com
*
*    This program is free software; you can redistribute it and/or modify it under the terms of the GNU General      Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
**/

#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <ctime>
#include <wiringPiI2C.h>
#include <lxpanel/plugin.h>

//returns the current battery capacity
int capacity(){
  
}

GtkWidget *test_new_instance(LXPanel *panel, config_setting_t *settings)
{
  //
     return gtk_image_new_from_stock(GTK_STOCK_OK, panel_get_icon_size(panel));
}

FM_DEFINE_MODULE(lxpanel_gtk, test)

LXPanelPluginInit fm_module_init_lxpanel_gtk = {
     .name = "Pi-Top Battery",
     .description = "Pi-Top Battery Status",
     .new_instance = test_new_instance
};


