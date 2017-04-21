/*
This descriptor instance should be defined in each plugin code as main
entry point for plugin creation. Primitive plugin example follows:
*/
#include <lxpanel/plugin.h>

GtkWidget *test_new_instance(LXPanel *panel, config_setting_t *settings)
{
     return gtk_image_new_from_stock(GTK_STOCK_OK, panel_get_icon_size(panel));
}

FM_DEFINE_MODULE(lxpanel_gtk, test)

LXPanelPluginInit fm_module_init_lxpanel_gtk = {
     .name = "Test plugin",
     .description = "An image with OK icon",
     .new_instance = test_new_instance
};


