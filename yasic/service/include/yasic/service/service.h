// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#pragma once

#include <typeindex>

namespace yasic::service
{
/**
 * Abstract base class for all services.
 *
 * Client service interfaces should derive from this class.
 */
class service_base
{
public:
	virtual ~service_base() = default;

private:
	virtual std::type_index type() const = 0;
};

/**
 * Template class for defining services.
 *
 * Client service implementations should derive from this class.
 */
template <typename T>
class service : public T
{
	friend class service_locator;
	std::type_index type() const override
	{
		return std::type_index{typeid(T)};
	}
};
} // namespace yasic::service