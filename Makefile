TARGETDIR=build

PDF_ASCIIDOC := $(patsubst %.adoc,$(TARGETDIR)/%.pdf,$(wildcard *.adoc))
HTML_ASCIIDOC := $(patsubst %.adoc,$(TARGETDIR)/%.html,$(wildcard *.adoc))

HTMLOPTIONS_ASCIIDOC=-b html5 -a data-uri
PDFOPTIONS_ASCIIDOC=-a source-highlighter=pygments -a pygments-style=xcode
#PDFOPTIONS_ASCIIDOC=-r asciidoctor-mathematical -a source-highlighter=pygments -a pygments-style=xcode

all : $(HTML_ASCIIDOC) $(PDF_ASCIIDOC)
	
$(TARGETDIR)/%.html: %.adoc
	asciidoctor $< $(HTMLOPTIONS_ASCIIDOC) -o $@

$(TARGETDIR)/%.pdf: %.adoc
	asciidoctor-pdf $< $(PDFOPTIONS_ASCIIDOC) -o $@

$(TARGETDIR):
	mkdir build

.PHONY: clean

clean:
	rm -f $(TARGETDIR)/*.html $(TARGETDIR)/*.pdf

rebuild: clean all
