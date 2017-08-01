%----------------------------------------------------------------------------%
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{psas-procedure-book}[2013/06/08 PSAS Procedure Book class]

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{letter}}
\ProcessOptions\relax
\LoadClass[12pt]{book}

%----------------------------------------------------------------------------%

\RequirePackage[paperwidth=8.5in,paperheight=11in,inner=2in,outer=1in,top=1in,bottom=1in]{geometry}
\usepackage{paralist}
	\let\itemize\compactitem
	\let\enditemize\endcompactitem
	\let\enumerate\compactenum
	\let\endenumerate\endcompactenum
	\let\description\compactdesc
	\let\enddescription\endcompactdesc
	\pltopsep=\medskipamount
	\plitemsep=1pt
	\plparsep=1pt


\renewcommand{\familydefault}{\sfdefault}
\renewcommand{\maketitle}{}
