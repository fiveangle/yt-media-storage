#pragma once

#include <array>
#include <cstddef>
#include <span>
#include <vector>

constexpr std::size_t CRYPTO_KEY_BYTES = 32u;
constexpr std::size_t CRYPTO_PLAIN_SIZE_HEADER = 4u;

std::array<std::byte, CRYPTO_KEY_BYTES> derive_key(
    std::span<const std::byte> password,
    std::span<const std::byte, 16> salt);

std::vector<std::byte> encrypt_chunk(
    std::span<const std::byte> plain,
    std::span<const std::byte, CRYPTO_KEY_BYTES> key,
    std::span<const std::byte, 16> file_id,
    uint32_t chunk_index);

std::vector<std::byte> decrypt_chunk(
    std::span<const std::byte> chunk_from_decoder,
    std::span<const std::byte, CRYPTO_KEY_BYTES> key,
    std::span<const std::byte, 16> file_id,
    uint32_t chunk_index);

void secure_zero(std::span<std::byte> data);
