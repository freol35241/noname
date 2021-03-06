#pragma once

#include "boost/hana.hpp"

// TODO(freol35241): Macro that allows default values and docstrings for Parameters/Inputs/Outputs

#define PARAMETERS(...)                                \
  struct Parameters {                                  \
    BOOST_HANA_DEFINE_STRUCT(Parameters, __VA_ARGS__); \
  } parameters;

#define INPUTS(...)                                \
  struct Inputs {                                  \
    BOOST_HANA_DEFINE_STRUCT(Inputs, __VA_ARGS__); \
  } inputs;

#define OUTPUTS(...)                                \
  struct Outputs {                                  \
    BOOST_HANA_DEFINE_STRUCT(Outputs, __VA_ARGS__); \
  } outputs;

namespace NoName {

  struct Block {
    struct Parameters {
      BOOST_HANA_DEFINE_STRUCT(Parameters);
    };
    struct Inputs {
      BOOST_HANA_DEFINE_STRUCT(Inputs);
    };
    struct Outputs {
      BOOST_HANA_DEFINE_STRUCT(Outputs);
    };

    Parameters parameters;
    Inputs inputs;
    Outputs outputs;

    virtual void evaluate(){};
    virtual void evaluate(double time) { this->evaluate(); };
  };

}  // namespace NoName
