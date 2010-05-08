# You need pandoc and sed to get the pdf of the guide.

SHELL  := /bin/bash

NAME   := using_git
TTEX   := $(NAME).tex
MD     := $(NAME).md
PDF    := $(NAME).pdf
OUTPUT := output.tex

define makepdf
echo Converting from Markdown to LaTeX                                                  ;\
pandoc --no-wrap -f markdown -t latex ../$(MD) > $(OUTPUT)                              ;\
sed -i 's+http://github.com/usm-data-analysis/Analyser/raw/master/doc/++' $(OUTPUT)     ;\
sed -i 's/includegraphics/img/' $(OUTPUT)                                               ;\
sed -r -i 's/^(begin|end)/\\&/' $(OUTPUT)                                               ;\
sed -i 's/{enumerate}\[1\.\]/{enumerate}/' $(OUTPUT)                                    ;\
sed -r -i 's/^(\\img.*$$)/\n&\n/' $(OUTPUT)                                             ;\
sed -r -i 's/(\\begin\{verbatim\}*$$)/\n\\begin{small}\n\\begin{shaded}\n&/' $(OUTPUT)  ;\
sed -r -i 's/(\\end\{verbatim\}*$$)/&\n\\end{shaded}\n\\end{small}\n/' $(OUTPUT)        ;\
sed -r -i 's/verb!([A-Za-z0-9 \/.\(\)<>=:-]+?)!/texttt{\1}/g' $(OUTPUT)                 ;\
sed -r -i 's/Analysis_files/Analysis\\_files/g' $(OUTPUT)                               ;\
echo Creating $(PDF)                                                                    ;\
pdflatex $(TTEX)                                                                        ;\
pdflatex $(TTEX)                                                                        ;\
echo Done.
endef


all: $(PDF)

$(PDF): ../using_git.md using_git.tex
	@$(makepdf)

clean:
	rm -f $(OUTPUT) *.{aux,log,out,toc} $(PDF)
