
all: jazz

jazz: jazz.cpp realbook.h
	g++ -Wall jazz.cpp -o jazz

evshow: evshow.cpp
	g++ -Wall evshow.cpp -o evshow

fmt:
	clang-format -i *.cpp *.h

clean:
	rm jazz evshow

install: jazz
	cat jazz.yaml.template | sed "s?INSTALL_DIR?$$(pwd)?g" >/etc/interception/udevmon.d/jazz.yaml
	systemctl restart udevmon.service

uninstall:
	rm -f /etc/interception/udevmon.d/jazz.yaml
	systemctl restart udevmon.service
