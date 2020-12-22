#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <pthread.h> 
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

// Kodok
move(kodok.y,kodok.x);
addch(' '); //clear
if (aksi == ATAS) {
    kodok.y = kodok.y-1 ; 
    if (kodok.y < 2) { // finish menyebrang
        printNotif("Selamat anda berhasil \\(^o^)/ Main lagi? (y/t)");
        isPause = true;
    }	
} else if (aksi==BAWAH) {
    kodok.y = kodok.y+1;
    if (kodok.y > max_y-5) {  // mentok ke bawah
        kodok.y = max_y-5;
    } 
} else if (aksi==KANAN) {
    kodok.x = kodok.x+1;  
    if (kodok.x > max_x-3) {  // mentok ke kanan
        kodok.x = max_x-3;
    } 
} else if (aksi==KIRI) {
    kodok.x = kodok.x-1;
    if (kodok.x < 3) {  // mentok ke kiri
        kodok.x = 3;
    } 
} 	
//gambar di tempat baru	
move(kodok.y,kodok.x);
addch('o');
refresh();	


// Mobil----------------------------------------------------------------
move(mobil.y,mobil.x);
addch(' ');  //clear

//jika sampai ke ujung, reset ke posisi awal 
if (mobil.x > max_x-5) {
    mobil.x = pRand(1,3); //mulai di posisi random 
}	
mobil.x++;  
move(mobil.y,mobil.x);
addch(mobil.karakter); //draw
refresh();
//cek tabrakan
if ((mobil.x == kodok.x) && (mobil.y == kodok.y)) {
    printNotif("Kodok tertabrak (x_x) Main lagi? (y/t)");
    isPause = true;
}	