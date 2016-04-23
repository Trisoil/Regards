// Le bloc ifdef suivant est la fa�on standard de cr�er des macros qui facilitent l'exportation 
// � partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compil�s avec le symbole DLLFORMATBPG_EXPORTS
// d�fini sur la ligne de commande. Ce symbole ne doit pas �tre d�fini pour un projet
// qui utilisent cette DLL. De cette mani�re, les autres projets dont les fichiers sources comprennent ce fichier consid�rent les fonctions 
// DLLFORMATBPG_API comme �tant import�es � partir d'une DLL, tandis que cette DLL consid�re les symboles
// d�finis avec cette macro comme �tant export�s.

#include <stdint.h>
#include <vector>
using namespace std;

#define ERROR_CONVERT_IMAGE 1001 //Cannot convert image
#define ERROR_ENCODING_PICTURE 1002 //Error while encoding picture
#define ERROR_ENCODING_ALPHA_PANE 1003 //Error while encoding picture (alpha plane)
#define ERROR_HEVC_DATA 1004 //Error while creating HEVC data
#define ERROR_WRITING_EXTENSION_DATA 1005 // Error while writing extension data
#define ERROR_WRITING_HEVC_PLANES 1006 //Error while writing HEVC image planes
#define ERROR_CREATING_IMAGE 1007 //Error while writing HEVC image planes


class CBpg
{
public:
    CBpg();
    virtual void GetDimensionsBpg(const char * fileName, int & width, int & height);
    virtual int GetPictureBpg(const char * fileName, int &size, int & width, int & height, uint8_t * & data, const int &outputSize);
    virtual int WritePictureBpg(const char * fileName, const uint8_t * data, int & width, int & height, int lossless_mode, int compress_level);
    virtual std::vector<uint8_t> GetPngPicture(const char * fileName, int &size, int & width, int & height);
    virtual void Test(const char * fileName, int * width, int * height);
    

};

// Constructor function and function type.
extern "C" CBpg *NewBpg(void);
typedef CBpg * Bpg_creator(void);

// Destructor function and function type.
extern "C" void DeleteBpg(CBpg * bpg);
typedef void Bpg_disposer(CBpg *);