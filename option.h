#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED

char lireOptionDifficulte();
void ecrireOptionDifficulte(const char);
const char* lireOptionDifficulteString();
const char* convertirOptionDifficulteString(const char);

char lireOptionMode();
void ecrireOptionMode(const char);
const char* lireOptionModeString();
const char* convertirOptionModeString(const char);

void ecrireFichierOptions();
void lireFichierOptions();
void retablirOptions();

#endif // OPTION_H_INCLUDED
