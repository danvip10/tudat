/*    Copyright (c) 2010-2017, Delft University of Technology
 *    All rigths reserved
 *
 *    This file is part of the Tudat. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    http://tudat.tudelft.nl/LICENSE.
 *
 *    References
 *      Eigen. http://eigen.tuxfamily.org/dox/TopicUnalignedArrayAssert.html, last accessed: 18th
 *          March, 2013.
 *
 */

#include <stdexcept>

#include <boost/make_shared.hpp>

#include "Tudat/Astrodynamics/BasicAstrodynamics/stateVectorIndices.h"
#include "Tudat/Astrodynamics/Ephemerides/cartesianStateExtractor.h"

namespace tudat
{
namespace ephemerides
{

boost::shared_ptr< Eigen::Vector6d > CartesianStateExtractor::extract(
        ParsedDataLineMapPtr dataLineMap )
{
    // Short-hand notation.
    namespace parsed_data_vector_utilities = input_output::parsed_data_vector_utilities;
    using Eigen::Vector6d;

    // Create a new CartesianElements object.
    boost::shared_ptr< Vector6d > cartesianElements
            = boost::allocate_shared< Vector6d >( Eigen::aligned_allocator< Vector6d >( ) );

    // Find and set Cartesian x coordinate.
    if ( checkOptionalFieldType( dataLineMap, 1,
                                 input_output::field_types::state::cartesianXCoordinate ) )
    {
        ( *cartesianElements )( orbital_element_conversions::xCartesianPositionIndex )
                = parsed_data_vector_utilities::getField< double >(
                    dataLineMap, input_output::field_types::state::cartesianXCoordinate );
    }

    else
    {
        boost::throw_exception( boost::enable_error_info(
                                 std::runtime_error(
                                        "No Cartesian x coordinate entry found." ) ) );
    }

    // Find and set Cartesian y coordinate.
    if ( checkOptionalFieldType( dataLineMap, 1,
                                 input_output::field_types::state::cartesianYCoordinate ) )
    {
        ( *cartesianElements )( orbital_element_conversions::yCartesianPositionIndex )
                = parsed_data_vector_utilities::getField< double >(
                    dataLineMap, input_output::field_types::state::cartesianYCoordinate );
    }

    else
    {
        boost::throw_exception( boost::enable_error_info(
                                 std::runtime_error( "No Cartesian y coordinate entry found." ) ) );
    }

    // Find and set Cartesian z coordinate.
    if ( checkOptionalFieldType( dataLineMap, 1,
                                 input_output::field_types::state::cartesianZCoordinate ) )
    {
        ( *cartesianElements )( orbital_element_conversions::zCartesianPositionIndex )
                = parsed_data_vector_utilities::getField< double >(
                    dataLineMap, input_output::field_types::state::cartesianZCoordinate );
    }

    else
    {
        boost::throw_exception( boost::enable_error_info(
                                 std::runtime_error(
                                        "No Cartesian z coordinate entry found." ) ) );
    }

    // Find and set Cartesian x velocity.
    if ( checkOptionalFieldType( dataLineMap, 1,
                                 input_output::field_types::state::cartesianXVelocity ) )
    {
        ( *cartesianElements )( orbital_element_conversions::xCartesianVelocityIndex )
                = parsed_data_vector_utilities::getField< double >(
                    dataLineMap, input_output::field_types::state::cartesianXVelocity );
    }
    else
    {
        boost::throw_exception( boost::enable_error_info(
                                   std::runtime_error(
                                        "No Cartesian x velocity entry found." ) ) );
    }

    // Find and set Cartesian y velocity.
    if ( checkOptionalFieldType( dataLineMap, 1,
                                 input_output::field_types::state::cartesianYVelocity ) )
    {
        ( *cartesianElements )( orbital_element_conversions::yCartesianVelocityIndex )
                = parsed_data_vector_utilities::getField< double >(
                    dataLineMap, input_output::field_types::state::cartesianYVelocity );
    }

    else
    {
        boost::throw_exception( boost::enable_error_info(
                                   std::runtime_error(
                                        "No Cartesian y velocity entry found." ) ) );
    }

    // Find and set Cartesian z velocity.
    if ( checkOptionalFieldType( dataLineMap, 1,
                                 input_output::field_types::state::cartesianZVelocity ) )
    {
        ( *cartesianElements )( orbital_element_conversions::zCartesianVelocityIndex )
                = parsed_data_vector_utilities::getField< double >(
                    dataLineMap, input_output::field_types::state::cartesianZVelocity );
    }

    else
    {
        boost::throw_exception( boost::enable_error_info(
                                   std::runtime_error(
                                        "No Cartesian z velocity entry found." ) ) );
    }

    return cartesianElements;
}

} // namespace ephemerides
} // namespace tudat
