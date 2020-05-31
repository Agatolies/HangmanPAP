#ifndef MYCONIO_H_INCLUDED
#define MYCONIO_H_INCLUDED

struct text_info {
    unsigned char winleft;
    unsigned char wintop;
    unsigned char winright;
    unsigned char winbottom;
    unsigned char attribute;
    unsigned char normattr;
    unsigned char currmode;
    unsigned char screenheight;
    unsigned char screenwidth;
    unsigned char curx;
    unsigned char cury;
};

enum COLORS { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
              DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
              LIGHTMAGENTA, YELLOW, WHITE } ;


void _setcursortype(int type);
char *cgets(char *str);
void clreol();
void clrscr();
void delline();

#define cprintf printf
#define cscanf scanf
/* Les fonctions � cprintf � et � cscanf � n'ont pas �t� r��crites, ceci est
   peut-�tre une erreur...
   En effet, � scanf � lit les donn�es � partir de � stdin � et les fonctions
   d'entr�e de la console lisent les donn�es � partir de � STD_INPUT_HANDLE �.
   Or il semblerait que � fflush(stdin) ; � n'ait pas le m�me effet que
   � FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)) ; �...
   A suivre... */

int cputs(const char *str) ;

int Gettext(int left, int top, int right, int bottom, void *destin) ;
#define gettext Gettext
/* Cette astuce a d� �tre utilis�e car la ligne
   � int gettext(int left, int top, int right, int bottom, void *destin) ; �
   produit un message d'erreur (sous Dev-C++) ! */

void gettextinfo(struct text_info *_r);

int MYgetch(void) ;
int MYgetche(void) ;
/*  � getch �, � getche � sont d�j� d�finies dans <conio.h> (mingw). Cependant,
    au m�me titre que � getchar � (stdio) ne consomme pas le caract�re <CR>,
    elles ne consomment pas le caract�re saisi par l'utilisateur (c'est � dire :
    elles n'enl�vent pas le caract�re du buffer d'entr�e). � MYgetch �,
    � MYgetche � vident le buffer. Attention, � MYgetch � et � MYgetche �
    n'enl�vent pas un caract�re, mais tous les caract�res disponibles. Gr�ce
    aux directives � #define � inclus dans MYconio.cpp, ce sont les fonctions
    � MYgetch � et � MYgetche � qui seront appel�es si dans un source on fait
    appel � � getch � ou � getche �. */

void gotoxy(int x, int y);

void highvideo();
void insline();
// kbhit : OK d�j� d�fini dans <conio.h> (mingw)
void lowvideo();
int movetext(int left, int top, int right, int bottom, int destleft, int desttop);
void normvideo();
// putch : OK d�j� d�fini dans <conio.h> (mingw)
int puttext(int left, int top, int right, int bottom, void *source);

void textattr(int _attr);
void textbackground(int _color);
void textcolor(int _color);
/* BLINK (clignotement) ne fonctionne pas ! Par contre, il est possible
   d'utiliser les oucleurs LIGHT pour le fond d'�cran, ce qui n'est pas le cas
   pour une application DOS.*/

/* � void textmode(int _mode); � n'a pas �t� r��crite, car  les modes
   d'affichage DOS n'ont aucun sens dans une application console Windows. */
// ungetch : OK d�j� d�fini dans <conio.h> (mingw)
int wherex();
int wherey();

void MYclrwin(int left, int top, int right, int bottom); // efface une zone
/* La fonction � window � de conio est fr�quemment utilis�e (suivi de
   � clrscr �) pour effacer une zone de l'�cran et modifier sa couleur en
   fonction des attribus mis � jour par � textcolor � ou � textbackground �.
   � MYclrwin � permet cela, mais elle n'interdit pas d'�crire en dehors
   de cette zone.*/

void MYwindow(int left, int top, int right, int bottom);
/* � MYwindow � permet de redimensionner la fen�tre de la console. Cependant,
   ce comportement, n'est pas celui de la fonction � window � de conio */

// void window(int left, int top, int right, int bottom);

#endif // MYCONIO_H_INCLUDED
