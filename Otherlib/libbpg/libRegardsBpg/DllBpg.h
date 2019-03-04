// Le bloc ifdef suivant est la fa�on standard de cr�er des macros qui facilitent l'exportation 
// � partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compil�s avec le symbole DLLFORMATBPG_EXPORTS
// d�fini sur la ligne de commande. Ce symbole ne doit pas �tre d�fini pour un projet
// qui utilisent cette DLL. De cette mani�re, les autres projets dont les fichiers sources comprennent ce fichier consid�rent les fonctions 
// DLLFORMATBPG_API comme �tant import�es � partir d'une DLL, tandis que cette DLL consid�re les symboles
// d�finis avec cette macro comme �tant export�s.
#ifdef DLLFORMATBPG_EXPORTS
#define DLLFORMATBPG_API __declspec(dllexport)
#else
#define DLLFORMATBPG_API __declspec(dllimport)
#endif

#include <stdint.h>

DLLFORMATBPG_API int BPG_GetDimensions(uint8_t * buf, size_t buf_len, int & width, int & height);
DLLFORMATBPG_API int BPG_GetPictureRGBA(uint8_t * buf, size_t buf_len, uint8_t * data, size_t data_len, int & width, int & height, bool flip);
DLLFORMATBPG_API int BPG_GetPictureBGRA(uint8_t * buf, size_t buf_len, uint8_t * data, size_t data_len, int & width, int & height, bool flip);
DLLFORMATBPG_API int BPG_SavePNGPicture(uint8_t * buf, size_t buf_len, int compress_level, int lossless_mode, int bit_depth, const char * filename);
DLLFORMATBPG_API uint8_t * BPG_ReadToPNGPicture(uint8_t * buf, size_t buf_len, size_t * buf_out, int bit_depth, int * returnValue);

