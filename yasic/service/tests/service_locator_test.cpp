// Copyright 2025 - David Brown <d.brown@bigdavedev.com>
// SPDX-License-Identifier: MIT
#include "yasic/service/service_locator.h"

#include "yasic/service/service.h"

#include "gtest/gtest.h"

class test_service_base : public yasic::service::service_base
{};

class test_service final : public yasic::service::service<test_service_base>
{};

TEST(ServiceLocatorTest, ServiceNotRegistered)
{
	auto const locator = std::make_shared<yasic::service::service_locator>();
	EXPECT_EQ(locator->get_service<test_service_base>(), nullptr);
}

TEST(ServiceLocatorTest, RegisterService)
{
	auto const locator = std::make_shared<yasic::service::service_locator>();
	auto const service = std::make_shared<test_service>();
	locator->register_service(service);

	EXPECT_EQ(locator->get_service<test_service_base>(), service);
}

TEST(ServiceLocatorTest, UnregisterService)
{
	auto const locator = std::make_shared<yasic::service::service_locator>();
	auto const service = std::make_shared<test_service>();
	locator->register_service(service);

	ASSERT_EQ(locator->get_service<test_service_base>(), service);

	locator->unregister_service<test_service_base>();
	EXPECT_EQ(locator->get_service<test_service_base>(), nullptr);
}
