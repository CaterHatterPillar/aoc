DAYS:=$(shell seq 25)
TESTS:= \
  $(foreach DAY,$(DAYS),$(addprefix test_,$(basename $(wildcard $(DAY)/*.cc))))

.PHONY: all $(TESTS)
all: $(TESTS)

$(TESTS): test_% : %
	./$*

CXXFLAGS:= \
  -Werror \
  -g
