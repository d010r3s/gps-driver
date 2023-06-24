# gps-driver
architecture and os 's 2nd project in the AMI's freshman year
<p>получает из config номер режима и работает в нём, выводя координаты и базовую логику положения объекта относительно какого-то уровня с замерами времени. драйвером координаты записываются в data и оттуда читаются демоном для обработки.</p>
# execution:
```
cd /home/.../gps-driver-main
gcc -o file1 daemon.c gps.h gps.c
gcc -o file2 application.c gps.h gps.c
./file1 & ./file2 &
```
