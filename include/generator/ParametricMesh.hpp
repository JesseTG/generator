// Copyright 2015 Markus Ilmola
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

#ifndef GENERATOR_PARAMETRICMESH_HPP
#define GENERATOR_PARAMETRICMESH_HPP

#include <functional>


#include "Triangle.hpp"
#include "MeshVertex.hpp"


namespace generator {


/// A mesh with values evaluated using a callback function.
class ParametricMesh {
public:

	class Triangles {
	public:

		Triangle generate() const;
		bool done() const noexcept;
		void next();
		void reset() noexcept;

	private:

		Triangles(const ParametricMesh& mesh);

		const ParametricMesh* mesh_;

		gml::uvec2 i_;

		bool even_;

	friend class ParametricMesh;
	};

	class Vertices {
	public:

		MeshVertex generate() const;
		bool done() const noexcept;
		void next();
		void reset() noexcept;

	private:

		Vertices(const ParametricMesh& mesh);

		const ParametricMesh* mesh_;

		gml::uvec2 i_;

	friend class ParametricMesh;
	};


	/// @param eval Callback that returns a ShapeVertex for given value.
	/// @param segments Number of subdivisions
	ParametricMesh(
		std::function<MeshVertex(const gml::dvec2& t)> eval,
		const gml::uvec2& segments = {16u, 16u}
	);

	ParametricMesh(const ParametricMesh&) = default;
	ParametricMesh(ParametricMesh&&) = default;

	ParametricMesh& operator=(const ParametricMesh&) = default;
	ParametricMesh& operator=(ParametricMesh&&) = default;

	Triangles triangles() const noexcept;

	Vertices vertices() const noexcept;

private:

	std::function<MeshVertex(const gml::dvec2& t)> eval_;

	gml::uvec2 segments_;
	
	gml::dvec2 delta_;

};


}

#endif