/*    Copyright (c) 2010-2017, Delft University of Technology
 *    All rigths reserved
 *
 *    This file is part of the Tudat. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    http://tudat.tudelft.nl/LICENSE.
 *
 */

#include <cmath>

#include "Tudat/Astrodynamics/BasicAstrodynamics/astrodynamicsFunctions.h"
#include "Tudat/Astrodynamics/BasicAstrodynamics/physicalConstants.h"
#include "Tudat/Mathematics/BasicMathematics/mathematicalConstants.h"

namespace tudat
{
namespace basic_astrodynamics
{

using mathematical_constants::PI;

//! Compute Kepler orbital period.
double computeKeplerOrbitalPeriod( const double semiMajorAxis,
                                   const double gravitationalParameterOfCentralBody,
                                   const double massOfOrbitingBody )
{
    return 2.0 * PI * std::sqrt( std::pow( semiMajorAxis, 3.0 )
                                   /  ( ( physical_constants::GRAVITATIONAL_CONSTANT
                                          * massOfOrbitingBody )
                                        + gravitationalParameterOfCentralBody ) );
}

//! Compute Kepler angular momentum.
double computeKeplerAngularMomentum( const double semiMajorAxis, const double eccentricity,
                                     const double gravitationalParameterOfCentralBody,
                                     const double massOfOrbitingBody )
{
    return massOfOrbitingBody * std::sqrt( gravitationalParameterOfCentralBody * semiMajorAxis
                                           * ( 1.0 - std::pow( eccentricity, 2.0 ) ) );
}

//! Compute Kepler mean motion.
double computeKeplerMeanMotion( const double semiMajorAxis,
                                const double gravitationalParameterOfCentralBody,
        const double massOfOrbitingBody )
{
    return std::sqrt( ( ( physical_constants::GRAVITATIONAL_CONSTANT * massOfOrbitingBody )
                      + gravitationalParameterOfCentralBody ) / std::pow( semiMajorAxis, 3.0 ) );
}

//! Compute Kepler orbital energy.
double computeKeplerEnergy( const double semiMajorAxis,
                            const double gravitationalParameterOfCentralBody,
                            const double massOfOrbitingBody )
{
    return -massOfOrbitingBody * gravitationalParameterOfCentralBody / ( 2.0 * semiMajorAxis );
}

//! Compute synodic period.
double computeSynodicPeriod( const double orbitalPeriodBody1, const double orbitalPeriodBody2 )
{
    return 1.0 / std::fabs( 1.0 / orbitalPeriodBody1 - 1.0 / orbitalPeriodBody2 );
}

} // namespace basic_astrodynamics
} // namespace tudat
