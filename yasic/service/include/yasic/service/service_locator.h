// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#pragma once

#include "yasic/service/service.h"

#include <map>
#include <memory>
#include <mutex>
#include <type_traits>

namespace yasic::service
{
/**
 * Service locator for managing services.
 */
class service_locator
{
	std::map<std::type_index, std::shared_ptr<service_base>> m_services;

	std::mutex mutable m_mutex;

public:
	/**
	 * Register a service.
	 *
	 * Registers a service of type T. If a service of the same type is already
	 * registered, it will not be registered again.
	 *
	 * @tparam T The type of service to register, must derive from service.
	 * @param service The service to register.
	 */
	template <typename T>
	void register_service(std::shared_ptr<T> const& service)
	{
		static_assert(std::is_base_of_v<service_base, T>,
		              "T must derive from service_base");

		std::scoped_lock const lock{m_mutex};

		if (m_services.contains(service->type()))
		{
			return;
		}
		m_services[service->type()] = service;
	}

	/**
	 * Unregister a service.
	 *
	 * @tparam T The type of service to unregister, must derive from
	 *           service_base.
	 */
	template <typename T>
	void unregister_service()
	{
		std::scoped_lock const lock{m_mutex};

		if (auto const type_index = std::type_index{typeid(T)};
		    m_services.contains(type_index))
		{
			m_services.erase(type_index);
		}
	}

	/**
	 * Retrieve a service.
	 *
	 * @tparam T Type of service to retrieve, must derive from service_base.
	 * @return Shared pointer to the service if registered, nullptr otherwise.
	 */
	template <typename T>
	std::shared_ptr<T> get_service() const
	{
		std::scoped_lock const lock{m_mutex};

		if (auto const entry = m_services.find(std::type_index{typeid(T)});
		    entry != m_services.end())
		{
			return std::static_pointer_cast<T>(entry->second);
		}
		return nullptr;
	}
};
} // namespace yasic::service
