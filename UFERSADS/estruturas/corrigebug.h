#ifndef STRING_H
# include <cstring>
#endif

void escritaLatim(char *text, ...);
void escreva(char *texto, ...);

void escritaLatim(char *text, ...) {
	char latin_char[] = "«¸È‚‡ÁÍ…Ù‹·ÌÛ˙™∫¡¬¿„√ Õ”‘ı’∞", *periodo;
	periodo = new char[strlen(text)];
	int latin_int[]= {128, 129, 130, 131, 133, 135, 136, 144, 147, 154, 160, 161, 162, 163, 166, 167, 181, 182, 183, 198, 199, 210, 214, 224, 226, 228, 229, 248},
	txt=0, ch=0, temp;
	unsigned short tamanhoPeriodo, tamanhoTabela = strlen(latin_char);
	
	periodo = text;
	tamanhoPeriodo = strlen(periodo);

//	strcpy(periodo, text);

	printf("%d \t%d\n", tamanhoPeriodo, tamanhoTabela);
	while (txt < tamanhoPeriodo) {
		ch = 0;
		while (ch < tamanhoTabela) {
			if (periodo[txt] == latin_char[ch]) {
				temp = latin_int[ch];
				printf("%c = %d\t", temp, temp);
//				getchar();
				break;
//				periodo[txt] = (char)latin_int[ch];
				txt++;
			}
			else ch++;
		}
		txt++;
	}

	printf("\n\n%c\n\n", periodo[10]);

//	strcpy (text, periodo);
	text = periodo;

//	delete [] periodo;
}

void escreva(char *texto, ...) {
//	char *senten = new char[strlen(texto)];

//	strcpy (senten, texto);
//	escritaLatim(senten);
	escritaLatim(texto);

	printf("\n");
	printf (texto);
//	printf (senten);
//	delete [] senten;

}

#define KEY_ESC		0x01
#define KEY_1		  0x02
#define KEY_2		  0x03
#define KEY_3		  0x04
#define KEY_4		  0x05
#define KEY_5		  0x06
#define KEY_6		  0x07
#define KEY_7		  0x08
#define KEY_8		  0x09
#define KEY_9		  0x0a
#define KEY_0		  0x0b
#define KEY_MINUS	   0x0c
#define KEY_EQUALS	  0x0d
#define KEY_BAKSP	   0x0e
#define KEY_TAB		0x0f
#define KEY_Q		  0x10
#define KEY_W		  0x11
#define KEY_E		  0x12
#define KEY_R		  0x13
#define KEY_T		  0x14
#define KEY_Y		  0x15
#define KEY_U		  0x16
#define KEY_I		  0x17
#define KEY_O		  0x18
#define KEY_P		  0x19
#define KEY_LFT_BRACKET  0x1a
#define KEY_RGT_BRACKET  0x1b
#define KEY_ENTER	   0x1c
#define KEY_CTRL	    0x1d
#define KEY_A		  0x1e
#define KEY_S		  0x1f
#define KEY_D		  0x20
#define KEY_F		  0x21
#define KEY_G		  0x22
#define KEY_H		  0x23
#define KEY_J		  0x24
#define KEY_K		  0x25
#define KEY_L		  0x26
#define KEY_SEMI	    0x27
#define KEY_APOS	    0x28
#define KEY_TILDE	   0x29
#define KEY_LSHIFT	  0x2a
#define KEY_BACK_SLASH   0x2b
#define KEY_Z		  0x2c
#define KEY_X		  0x2d
#define KEY_C		  0x2e
#define KEY_V		  0x2f
#define KEY_B		  0x30
#define KEY_N		  0x31
#define KEY_M		  0x32
#define KEY_COMMA	   0x33
#define KEY_PERIOD	  0x34
#define KEY_FWD_SLASH    0x35
#define KEY_RSHIFT	  0x36
#define KEY_PRT_SCRN	0x37
#define KEY_ALT		0x38
#define KEY_SPACE	   0x39
#define KEY_CAPS_LOCK    0x3a
#define KEY_F1		 0x3b
#define KEY_F2		 0x3c
#define KEY_F3		 0x3d
#define KEY_F4		 0x3e
#define KEY_F5		 0x3f
#define KEY_F6		 0x40
#define KEY_F7		 0x41
#define KEY_F8		 0x42
#define KEY_F9		 0x43
#define KEY_F10		0x44
#define KEY_F11		0xffffff85
#define KEY_F12		0x58
#define KEY_NUM_LOCK	0x45
#define KEY_SCROLL_LOCK  0x46
#define KEY_HOME	    0x47
#define KEY_UP		 0x48
#define KEY_PGUP	    0x49
#define KEY_KEYPAD_MINUS 0x4a
#define KEY_LEFT	    0x4b
#define KEY_CENTER	  0x4c
#define KEY_RIGHT	   0x4d
#define KEY_KEYPAD_PLUS  0x4e
#define KEY_END		0x4f
#define KEY_DOWN	    0x50
#define KEY_PGDWN	   0x51
#define KEY_INS		0x52
#define KEY_DEL		0x53
#define ALT_F4		 0x6b
