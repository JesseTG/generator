// Copyright 2015 Markus Ilmola
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

#ifndef GENERATOR_TORUS_HPP
#define GENERATOR_TORUS_HPP

#include "AxisSwapMesh.hpp"
#include "CircleShape.hpp"
#include "LatheMesh.hpp"
#include "TranslateShape.hpp"


namespace generator {


/// Torus centered at origin on the xy-plane.
/// @image html TorusMesh.svg
class TorusMesh :
	private AxisSwapMesh<LatheMesh<TranslateShape<CircleShape>>> {
public:

	/// @param minor Radius of the minor (inner) ring
	/// @param major Radius of the major (outer) ring
	/// @param slices Subdivisions around the minor ring
	/// @param segments Subdivisions around the major ring
	/// @param minorStart Counterclockwise angle relative to the xy-plane.
	/// @param minorSweep Counterclockwise angle around the circle.
	/// @param majorStart Counterclockwise angle around the z-axis relative to the x-axis.
	/// @param majorSweep Counterclockwise angle around the z-axis.
	TorusMesh(
		double minor = 0.25,
		double major = 1.0,
		unsigned slices = 16u,
		unsigned segments = 32u,
		double minorStart = 0.0,
		double minorSweep = gml::radians(360.0),
		double majorStart = 0.0,
		double majorSweep = gml::radians(360.0)
	);

	using AxisSwapMesh::triangles;

	using AxisSwapMesh::vertices;

};


}


#endif