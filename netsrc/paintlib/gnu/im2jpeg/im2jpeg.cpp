
#include "im2jpeg.h"

std::string filein;
std::string fileout;

int main(int nargs, char** args)
{
  PLAnyBmp bmp;
  PLAnyPicDecoder decoder;
  PLJPEGEncoder encoder;

  if (nargs==1)
  {
    printusemessage();
    exit(0);
  }

  parseargs(nargs, args);

  // Open the graphic file.
  try
  {
    decoder.MakeBmpFromFile(filein.c_str(),
   &bmp);

    encoder.MakeFileFromBmp(fileout.c_str(),
   &bmp);
    return 0;
  }
  catch (PLTextException e)
  {
    std::cerr<<"\nim2jpeg: "<<(const char*)e <<std::endl;
    return 1;
  }
}

//----------------------------------------
//
// FUNCTION: parseargs
//
// PORPOUSE: Parse command line arguments
//
//----------------------------------------
void parseargs(int nargs, char** args)
{
  int i;

  for (i=1; i<nargs; i++)
  {
    std::string arg(args[i]);
    if (arg=="-o")
    {
      i++;
      if (i<nargs)
      {
        fileout = args[i];
      }
      else
      {
        std::cerr << "im2jpeg: -o needs a file name.\n";
    exit(1);
      }
    }
    else
    {
      if (filein.empty())
    filein = args[i];
      else
      {
        std::cerr << "im2jpeg: Only accepts one file input.\n";
        exit(1);
      }
    }
  }

  if (fileout.empty())
  {
    fileout = filein.substr(0,filein.size()-4);
    fileout+=".jpg";
  }

  std::cerr<<"im2jpeg: Input file: "<<filein<<std::endl;
  std::cerr<<"im2jpeg: Output file: "<<fileout<<std::endl;
}

//-------------------------------------------
//
// FUNCTION: printusemessage
//
// PORPOUSE: Print help abaut program use.
//
//-------------------------------------------
void printusemessage()
{
  std::cerr << "\nim2jpg: Jose Miguel Buenaposada (jmbuena@dia.fi.upm.es) ---------------\n";
  std::cerr << "Use: im2jpg <filein> [-o fileout]\n";
  std::cerr << "   -o fileout: name of the output file.\n";
}
