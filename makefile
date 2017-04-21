all:
	g++ -Wall `pkg-config --cflags gtk+-2.0 lxpanel` -shared -fPIC battery.cpp -o battery.so `pkg-config --libs lxpanel`

test:
	gcc -Wall `pkg-config --cflags gtk+-2.0 lxpanel` -shared -fPIC test.c -o test.so `pkg-config --libs lxpanel`

clean:
	rm battery.so

install:
	cp battery.so /usr/lib/lxpanel/plugins/

uninstall:
	rm /usr/lib/lxpanel/plugins/battery.so
