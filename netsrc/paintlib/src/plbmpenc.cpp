/*
/--------------------------------------------------------------------
|
|      Windows bitmap file encoder. Encodes 1, 4, 8, 24 and 32 bpp
|      bitmaps to a 1, 4, 8 or 24 bpp uncompressed BMP file
|
|      Copyright (c) 1996-2002 Ulrich von Zadow
|
\--------------------------------------------------------------------
*/
#include "plbmpenc.h"
#include "plwindefs.h"
#include "plexcept.h"


/////////////////////////////////////////////////////////////////////
// Class functions

PLBmpEncoder::PLBmpEncoder
  () : PLPicEncoder()
    // Creates an encoder
{
  // nothing to do (yet)
}


PLBmpEncoder::~PLBmpEncoder
    ()
{
  // nothing to do (yet)
}

int PLBmpEncoder::GetLineMemNeeded (PLLONG width, PLWORD BitsPerPixel)
{
  // Calculate memory per line.
  int LineMem = width * BitsPerPixel / 8;

  if (BitsPerPixel == 1 && width % 8)
    ++LineMem;

  // DWORD alignment
  return ((LineMem + 3) & ~3);
}


void PLBmpEncoder::DoEncode
    ( PLBmpBase * pBmp,
      PLDataSink * pSink
    )
{
  int BPP = pBmp->GetBitsPerPixel();

  WINBITMAPFILEHEADER BFH;
  BFH.bfType = *((PLWORD*)"BM");
  BFH.bfReserved1 = 0;
  BFH.bfReserved2 = 0;
  BFH.bfOffBits = sizeof (WINBITMAPFILEHEADER) +
                  sizeof (WINBITMAPINFOHEADER);
  if (BPP <= 8)   // include palette
    BFH.bfOffBits += (1 << BPP) * sizeof(WINRGBQUAD);

  BFH.bfSize = BFH.bfOffBits;
  BFH.bfSize += pBmp->GetHeight()*GetLineMemNeeded(pBmp->GetWidth(), static_cast<PLWORD>(BPP));

  pSink->WriteNBytes( sizeof (WINBITMAPFILEHEADER), (PLBYTE *) &BFH);

  WINBITMAPINFOHEADER FileBMI;
  FileBMI.biSize = sizeof(WINBITMAPINFOHEADER);
  FileBMI.biWidth = pBmp->GetWidth ();
  FileBMI.biHeight = pBmp->GetHeight ();
  FileBMI.biPlanes = 1;
  FileBMI.biCompression = BI_RGB;
  FileBMI.biSizeImage = 0; // may be 0 for non-compressed files
  FileBMI.biXPelsPerMeter = (int)((float)pBmp->GetResolution().x * 39.37f+0.5);
  FileBMI.biYPelsPerMeter = (int)((float)pBmp->GetResolution().y * 39.37f+0.5);
  FileBMI.biClrUsed = 0;
  FileBMI.biClrImportant = 0;

  int x,y;
  if (BPP <= 8)
  {
    PLBYTE * pCurLine;
    FileBMI.biBitCount = static_cast<PLWORD>(BPP);  // not 32...
    pSink->WriteNBytes (sizeof (WINBITMAPINFOHEADER), (PLBYTE *) &FileBMI);

    // Write Palette
    PLPixel32 * pPal = pBmp->GetPalette();
    for (int i=0; i<(1<<BPP); i++)
    {
      pSink->WriteByte (pPal[i].GetB());
      pSink->WriteByte (pPal[i].GetG());
      pSink->WriteByte (pPal[i].GetR());
      pSink->WriteByte (pPal[i].GetA());
    }

    for (y=FileBMI.biHeight-1; y>=0; y--)
    {
      pCurLine = pBmp->GetLineArray()[y];
      int BytesPerLine = pBmp->GetWidth()*pBmp->GetBitsPerPixel()/8;
      pSink->WriteNBytes (BytesPerLine, pCurLine);
      int PadBytes = GetLineMemNeeded(pBmp->GetWidth(), static_cast<PLWORD>(BPP)) 
                   - BytesPerLine;

      pSink->Skip(PadBytes);
    }
  }
  else if (BPP == 16)
  {
    PLPixel16 * pCurLine;
    FileBMI.biBitCount = 24;  // not 32...
    pSink->WriteNBytes (sizeof (WINBITMAPINFOHEADER),(PLBYTE *) &FileBMI);

    int LinePadding = 4-((FileBMI.biWidth*3)&3);
    if (LinePadding == 4)
      LinePadding = 0;
    for (y=FileBMI.biHeight-1; y>=0; y--)
    {
      pCurLine = pBmp->GetLineArray16()[y];
      for (x=0; x<FileBMI.biWidth; x++)
      {
        pSink->WriteByte (pCurLine[x].GetB());
        pSink->WriteByte (pCurLine[x].GetG());
        pSink->WriteByte (pCurLine[x].GetR());
      }
      pSink->WriteNBytes(LinePadding,(PLBYTE *) " ");
    }
  }
  else if (BPP == 24)
  {
    PLPixel24 * pCurLine;
    FileBMI.biBitCount = 24;  // not 32...
    pSink->WriteNBytes (sizeof (WINBITMAPINFOHEADER),(PLBYTE *) &FileBMI);

    int LinePadding = 4-((FileBMI.biWidth*3)&3);
    if (LinePadding == 4)
      LinePadding = 0;
    for (y=FileBMI.biHeight-1; y>=0; y--)
    {
      pCurLine = pBmp->GetLineArray24()[y];
      for (x=0; x<FileBMI.biWidth; x++)
      {
        pSink->WriteByte (pCurLine[x].GetB());
        pSink->WriteByte (pCurLine[x].GetG());
        pSink->WriteByte (pCurLine[x].GetR());
      }
      pSink->WriteNBytes(LinePadding,(PLBYTE *) " ");
    }
  }
  else if (BPP == 32)
  {
    PLPixel32 * pCurLine;
    FileBMI.biBitCount = 24;  // not 32...
    pSink->WriteNBytes (sizeof (WINBITMAPINFOHEADER),(PLBYTE *) &FileBMI);

    int LinePadding = 4-((FileBMI.biWidth*3)&3);
    if (LinePadding == 4)
      LinePadding = 0;
    for (y=FileBMI.biHeight-1; y>=0; y--)
    {
      pCurLine = pBmp->GetLineArray32()[y];
      for (x=0; x<FileBMI.biWidth; x++)
      {
        pSink->WriteByte (pCurLine[x].GetB());
        pSink->WriteByte (pCurLine[x].GetG());
        pSink->WriteByte (pCurLine[x].GetR());
      }
      pSink->WriteNBytes(LinePadding,(PLBYTE *) " ");
    }
  }
  else 
  {
      throw (PLTextException (PL_ERRFORMAT_NOT_SUPPORTED, " bitsPerPixel Unsupported."));
  }

}

/*
/--------------------------------------------------------------------
|
|      $Log: plbmpenc.cpp,v $
|      Revision 1.9  2004/09/11 12:41:35  uzadow
|      removed plstdpch.h
|
|      Revision 1.8  2004/06/19 18:16:33  uzadow
|      Documentation update
|
|      Revision 1.7  2002/03/31 13:36:41  uzadow
|      Updated copyright.
|
|      Revision 1.6  2001/10/21 17:12:39  uzadow
|      Added PSD decoder beta, removed BPPWanted from all decoders, added PLFilterPixel.
|
|      Revision 1.5  2001/10/16 17:12:26  uzadow
|      Added support for resolution information (Luca Piergentili)
|
|      Revision 1.4  2001/10/06 22:37:08  uzadow
|      Linux compatibility.
|
|      Revision 1.3  2001/10/06 22:03:26  uzadow
|      Added PL prefix to basic data types.
|
|      Revision 1.2  2001/10/06 20:44:45  uzadow
|      Linux compatibility
|
|      Revision 1.1  2001/09/16 19:03:22  uzadow
|      Added global name prefix PL, changed most filenames.
|
|      Revision 1.8  2001/02/04 14:31:52  uzadow
|      Member initialization list cleanup (Erik Hoffmann).
|
|      Revision 1.7  2000/12/02 19:52:12  uzadow
|      no message
|
|      Revision 1.6  2000/12/02 19:50:01  uzadow
|      Added Logging.
|
|    31.10.2000 - Jos� Miguel Buenaposada
|                 Corrected the order for writing color channels
|                 to work with other channels orders.
|
|    27.08.2000 - Martin Skinner
|                 now uses PLDataSink instead of MFC CFile
|                 moved to a new class PLBmpEncoder
|
|    11.01.2000 - Michael Salzlechner
|                 moved code from PLWinBmp to CAfxBmp
|
|    21.01.99 - Added by M.Skinner
|               Moved program logic from 
|               PLWinBmp::SaveAsBmp(const char *) to here
|
\--------------------------------------------------------------------
*/
