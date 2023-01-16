#ifndef PRINTPARAMETERS_H
#define PRINTPARAMETERS_H

#include <cmath>
#include <vector>
#include <string>

#define INVALID_PAGE 0

typedef std::vector<size_t> PageSequence;
typedef std::vector<std::pair<size_t, size_t>> PageRangeList;

class PrintParameters
{
public:

  enum Format
  {
    PDF,
    Postscript,
    PWG,
    URF,
    Invalid
  };

  Format format = PDF;

  size_t colors = 3; // RGB
  size_t bitsPerColor = 8;
  // More color is black, like for black_1, black_8.
  // False for regular modes like sRGB and sGray.
  bool black = false;
  size_t quality = 0; // Default
  bool antiAlias = false;
  std::string paperSizeName = "iso_a4_210x297mm";

  size_t hwResW = 300;
  size_t hwResH = 300;

  enum PaperSizeUnits
  {
    Pixels,
    Millimeters,
    Inches
    // Feet
    // Arms
    // Legs
  };

  PaperSizeUnits paperSizeUnits = Millimeters;
  float paperSizeW = 210; // A4
  float paperSizeH = 297; // A4

  bool duplex = false;
  bool tumble = false;

  bool backHFlip = false;
  bool backVFlip = false;

  size_t documentCopies = 1;
  size_t pageCopies = 1;

  PageRangeList pageRangeList;

  size_t getPaperSizeWInPixels() const;
  size_t getPaperSizeHInPixels() const;

  size_t getPaperSizeInPixels() const;

  float getPaperSizeWInMillimeters() const;
  float getPaperSizeHInMillimeters() const;

  float getPaperSizeWInPoints() const;
  float getPaperSizeHInPoints() const;

  size_t getPaperSizeWInBytes() const;
  size_t getPaperSizeInBytes() const;

  PageSequence getPageSequence(size_t pages) const;

  bool setPageRange(const std::string& rangeStr);

  bool setPaperSize(const std::string& sizeStr);

  bool setColorMode(std::string colorMode);

private:

  double round2(double d) const
  {
    return round(d*100)/100;
  }

};

#endif //PRINTPARAMETERS_H
