# header-merger
Merges multiple header files into a single one

## Purpose
This program is used for merging multiple header files into a **single-file library**. It is used for merging the libraries developed in other repositories (ie [`Simple-Image-Library`](https://github.com/mrc-tech/Bitmap) and [`AutoMat`](https://github.com/mrc-tech/AutoMat)) into a single file. This is particulary useful for portability.

## How it works
Substitute the statements `#include "filename"` with the actual content of the `filename` file. It does this inclusion recursively, so if there is another `#include ""` statement inside this is substituted with the actual file content.
