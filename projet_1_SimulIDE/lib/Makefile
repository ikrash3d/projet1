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
##### 		   *Makefile Librairie*			 #####
##################################################

#include du Makefile commun
include ../Makefile

#####      Details specifique a la cible       #####
#####  Vous devez les adapter a votre projet   #####

# Nom de la librairie
PROJECTNAME=libstatique

####################################################
#####         Configuration terminee           #####
#####                                          #####
#####  Le reste de cette section contient les  #####
##### details d'implementation vous permettant #####
##### de mieux comprendre le fonctionnement de ##### 
#####   ce Makefile en vue de sa modification  #####
####################################################

####### variable #######

# Creation de la librairie
AR=ar

####### Cible (Target) #######

#Nom des cibles par defaut
TRG=$(PROJECTNAME).a

####### Creation des commandes du Makefile ####### 

# Make all permet simplement de compiler le projet
all: $(TRG) $(HEXROMTRG)

# Implementation de la cible
$(TRG): $(OBJDEPS)
	$(AR) -crs $(TRG) $(OBJDEPS)

# Production des fichiers object
# De C a objet
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# De C++ a objet
%.o: %.cpp
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $<

#####                    EOF                   #####