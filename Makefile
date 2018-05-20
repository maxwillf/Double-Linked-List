Target = list 
INCLUDES = include
CXX = g++
CXXFLAGS = -W -std=c++11 -g -ggdb -I $(INCLUDES)
DOCS = docs 
SRCDIR = src
OBJDIR = obj

HEADERS := $(wildcard $(INCLUDES) *.h)
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

<<<<<<< 716cc6586d5cdcb74e5d6e5ae0a95d580aa8cbb5
all: project # docs
=======
all: project #docs
>>>>>>> meh
project: $(OBJECTS) 
	@echo "Linkin Files: " $(OBJECTS) $(DRIVER)
	@$(CXX) $(OBJECTS) $(DRIVER)  $(CXXFLAGS) -o $(Target)
	@echo "Linkin complete!"

docs: 
	@echo "Generating Documentation"
	@doxygen config
	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Sources $<" 
	@echo "Compiling Files $< to  $@ "
	@echo "Compiled "$<" Succesfully!"

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean  clean_docs clean_proj
<<<<<<< 716cc6586d5cdcb74e5d6e5ae0a95d580aa8cbb5
clean: clean_proj  clean_docs
=======
clean: clean_proj  #clean_docs
>>>>>>> meh

clean_proj:
	@rm -r $(OBJDIR)
	@rm $(Target)
	@echo "Cleanup Complete!"

clean_docs: $(DOCS)
	@rm -r $(DOCS)
