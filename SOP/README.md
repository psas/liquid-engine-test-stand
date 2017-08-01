# PSAS Liquid Fueled Engine Test Stand Procedure Book

## Objectives

- [ ] Determine Subject headings and fill through the "Rough Draft"
- [ ] Identify individual procedures which belong in this book
- [ ] Personalize the book to LFETS/LFE/EFS/CFT as appropriate

## Editing

The raw book files are
[markdown](http://daringfireball.net/projects/markdown/syntax). Please keep each
major section in it's own file for easier managment.  Files can be editied in
place using github's web interface, or simply clone the repo and open the files
in your favorite text editor.



## Building Book Locally


### Prerequisites

LaTeX and 
[pandoc](http://johnmacfarlane.net/pandoc/README.html) installed with LaTeX
support.

**NOTE**: pandoc > 1.12.1 required to use the yaml_metadata_block format in
common with jekyll


### Build

	$ make pdf

For a booklet (printable full duplex on US Letter paper, to be folded in half
and staple bound.  This requires a fair amount of non standard pdf and ps tools
(sorry) check the Makefile and error ouput for hints.

    $ make booklet

