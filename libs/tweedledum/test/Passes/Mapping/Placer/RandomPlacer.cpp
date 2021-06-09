/*------------------------------------------------------------------------------
| Part of Tweedledum Project.  This file is distributed under the MIT License.
| See accompanying file /LICENSE for details.
*-----------------------------------------------------------------------------*/
#include "tweedledum/Passes/Mapping/Placer/RandomPlacer.h"

#include "tweedledum/IR/Circuit.h"
#include "tweedledum/IR/Qubit.h"
#include "tweedledum/Target/Device.h"

#include <catch.hpp>

TEST_CASE("RandomPlacer test cases", "[RandomPlacer][mapping]")
{
    using namespace tweedledum;
    Circuit circuit;
    SECTION("Empty circuit") {
        Device device = Device::path(circuit.num_qubits());
        auto placement = random_place(device, circuit);
        CHECK(placement);
    }
    SECTION("Simple circuit") {
        circuit.create_qubit();
        circuit.create_cbit();
        circuit.create_qubit();
        circuit.create_cbit();
        circuit.create_qubit();
        circuit.create_cbit();

        Device device = Device::path(circuit.num_qubits());
        auto placement = random_place(device, circuit);
        CHECK(placement);
    }
}
