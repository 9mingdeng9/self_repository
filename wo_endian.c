#include "wo_endian.h"
#include <string.h>

uintmax_t bytes2uint(const uint8_t *net_bytes, unsigned size)
{
	unsigned i;
	uintmax_t ret = 0;

	for (i = 0; i < size; i++)
		ret = (ret << 8) + net_bytes[i];

	return ret;
}

/// @cond
#define MIN(a, b) ((a) > (b) ? (b) : (a))
/// @endcond
uintmax_t uint2bytes(uintmax_t uint, uint8_t *net_bytes, unsigned size)
{
	uintmax_t tmp = uint;

	if (net_bytes == NULL || size == 0)
		return 0;

	// 将 net_bytes 清零，以免它的尺寸较大时，低地址的部分数字不为 0
	memset(net_bytes, 0, size);

	for (int i = 0; i < MIN(sizeof(uint), size); i++) {
		// 从 net_bytes 的最后一个 uint8_t 开始填值
		net_bytes[size - 1 - i] = tmp & 0xFF;
		tmp >>= 8;
	}

	if (size < sizeof(uint)) {
		int left = sizeof(uint) - size;
		return uint << (8 * left) >> (8 * left);
	} else
		return uint;
}
