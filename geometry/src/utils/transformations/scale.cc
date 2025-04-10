#include "transformer.h"
#include <iostream>
#include <array>
#include <vector>

std::vector<double> Transformer::scale(std::vector<double> params, double factor) {

    std::vector<double> scaledParams;

    scaledParams.reserve(params.size());
    for (size_t i = 0; i < params.size(); ++i) {
        scaledParams.push_back(params[i] * factor);
    }
    return scaledParams;
}
