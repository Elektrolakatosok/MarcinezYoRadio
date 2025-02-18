#ifndef utf8RusGFX_h
#define  utf8RusGFX_h

// Hungarian chars: áíűőüöúóé ÁÍŰŐÜÖÚÓÉ

char* DspCore::utf8Rus(const char* str, bool uppercase) {
 int index = 0;
  static char strn[BUFLEN];
  strlcpy(strn, str, BUFLEN); 
 
  if (uppercase) { // Umschalten Groß- Kleinschreibung
  for (char *iter = strn; *iter != '\0'; ++iter)
  *iter = toupper(*iter); 
  }

if(L10N_LANGUAGE==EN)  return strn;
  while (strn[index])
  {
    if (strn[index] == 0xC3) // Amelyik UTF-8 karakterek első bájtja C3, azokat mind ebbe a csoportba tedd!
    {
      switch (strn[index + 1]) {
        case 0xA1: {
			if (!uppercase){ 
			strn[index] = 0x86;} // *á
			else {
			strn[index] = 0x8F;} // *Á
            break;
        }
			case 0x81: { 
			strn[index] = 0x8F; // *Á
            break;
            } 

		case 0xAD: {
			if (!uppercase){ 
			strn[index] = 0x8C;} // *í
			else {
			strn[index] = 0x8D;} // *Í
              break;
		}
			case 0x8D: { 
			strn[index] = 0x8D; // *Í
            break;
            } 
			
		case 0xBC: { 
			if (!uppercase){ 
			strn[index] = 0x81;} // *ü
			else {
			strn[index] = 0x9A;} // *Ü
            break;
        }
			case 0x9C: { 
			strn[index] = 0x9A; // *Ü
            break;
            } 
			
		case 0xB6: { 
			if (!uppercase){ 
			strn[index] = 0x94;} // *ö
			else {
			strn[index] = 0x99;} // *Ö
            break;
        }
			case 0x96: { 
			strn[index] = 0x99; // *Ö
            break;
            } 

		case 0xBA: { 
			if (!uppercase){ 
			strn[index] = 0x97;} // *ú
			else {
			strn[index] = 0x9C;} // *Ú
            break;
        }
			case 0x9A: { 
			strn[index] = 0x9C; // *Ú
            break;
            } 

		case 0xB3: { 
			if (!uppercase){ 
			strn[index] = 0x96;} // *ó
			else {
			strn[index] = 0x95;} // *Ó
            break;
        }
			case 0x93: { 
			strn[index] = 0x95; // *Ó
            break;
            } 

		case 0xA9: { 
			if (!uppercase){ 
			strn[index] = 0x82;} // *é
			else {
			strn[index] = 0x90;} // *É
            break;
        }
			case 0x89: { 
			strn[index] = 0x90; // *É
            break;
            } 
	  }
		int sind = index + 2;
		while (strn[sind]) {
        strn[sind - 1] = strn[sind];
        sind++;
      }
    strn[sind - 1] = 0;
    }

if (strn[index] == 0xC5)  // Amelyik UTF-8 karakterek első bájtja C5, azokat mind ebbe a csoportba tedd!
    {
	  switch (strn[index + 1]) {

		case 0xB1: {
			if (!uppercase){ 
			strn[index] = 0x8B;} // *ű
			else {
			strn[index] = 0x98;} // *Ű
              break;
		}
			case 0xB0	: { 
			strn[index] = 0x98; // *Ű
            break;
            } 
		
		case 0x91: {
			if (!uppercase){ 
			strn[index] = 0x93;} // *ő
			else {
			strn[index] = 0x9B;} // *Ő
              break;
		}
			case 0x90: { 
			strn[index] = 0x9B; // *Ő
            break;
            } 

  } 

		int sind = index + 2;
		while (strn[sind]) {
        strn[sind - 1] = strn[sind];
        sind++;
      }
      strn[sind - 1] = 0;
    
	}
// ab hier deine Anpassung einfühgen

    index++;
  }
return strn;
}
#endif