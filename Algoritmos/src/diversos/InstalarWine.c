#include <stdio.h>

int main(void){

system("cd \"/media/HUGO/A Salada\"");
system("sudo dpkg -i libunistring0_0.9.3-4_i386.deb");
system("sudo dpkg -i libgettextpo0_0.18.1.1-5ubuntu3_i386.deb");
system("sudo dpkg -i libopenal1_1.13-2_i386.deb");
system("sudo dpkg -i libmpg123-0_1.12.1-3.1fakesync1_i386.deb");
system("sudo dpkg -i wine1.3_1.3.28-0ubuntu2~oneiric1_i386.deb");
system("sudo dpkg -i wine1.2-gecko_1.0.0-0ubuntu4_i386.deb");
system("sudo dpkg -i wine-gecko_1.1.42-0ubuntu4_all.deb");

return (0);
}
