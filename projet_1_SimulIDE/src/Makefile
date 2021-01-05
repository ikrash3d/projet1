########       AVR Project Makefile       ########
#####                                        #####
#####      Makefile produit et ecrit par     #####
#####   Simon Barrette & Jerome Collin pour  #####
#####           INF1900 - 2016               #####
#####                                        #####
#####         Inspire de Pat Deegan -        #####
#####  Psychogenic Inc (www.psychogenic.com) #####
##################################################

########       		Modifié par			  ########
#####                                        #####
#####           CHeklat, Samy (1937812)      #####
#####      Benchoubane, Abderraouf (1946665) #####
#####         Bonhomme, Philippe (2012859)   #####
#####         Ringuet, William (2015739)     #####
#####            							 #####
##### 			*Makefile Source*			 #####
##################################################

#include du Makefile commun
include ../Makefile

#####      Details specifique a la cible       #####
#####  Vous devez les adapter a votre projet   #####


# Nom de votre projet
# (utilisez un seul mot, exemple: 'monprojet')
PROJECTNAME=the_firmware



# Inclusions additionnels (ex: -I/path/to/mydir)
INC= -L ../lib/

# Libraires a lier (ex: -lmylib)
LIBS= -L ../lib/ -lstatique


####################################################
#####         Configuration terminee           #####
#####                                          #####
#####  Le reste de cette section contient les  #####
##### details d'implementation vous permettant #####
##### de mieux comprendre le fonctionnement de ##### 
#####   ce Makefile en vue de sa modification  #####
####################################################

####### Cible (Target) #######

#Nom des cibles par defaut
TRG=$(PROJECTNAME).elf
HEXROMTRG=$(PROJECTNAME).hex
HEXTRG=$(HEXROMTRG) $(PROJECTNAME).ee.hex

####### Definition de tout les fichiers objets #######

# Cette fonction permet de differencier les fichiers .c
# des fichiers .cpp
# Fichier C
CFILES=$(filter %.c, $(PRJSRC))
# Fichier C++
CPPFILES=$(filter %.cpp, $(PRJSRC))

# Liste de tout les fichiers objet que nous devons creer
OBJDEPS=$(CFILES:.c=.o) \
	$(CPPFILES:.cpp=.o)
	

####### Creation des commandes du Makefile ####### 

# Creation des cibles Phony (Phony Target)
# Make all permet simplement de compiler le projet
#
all: $(TRG) $(HEXROMTRG)

# Implementation de la cible
$(TRG): $(OBJDEPS)
	$(CC) $(LDFLAGS) -o $(TRG) $(OBJDEPS) \
	-lm $(LIBS)


# Production des fichiers hex a partir des fichiers elf
%.hex: %.elf
	$(OBJCOPY) -j .text -j .data \
		-O $(HEXFORMAT) $< $@


#####                    EOF                   #####
