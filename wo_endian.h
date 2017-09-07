#ifndef WO_ENDIAN_H
#define WO_ENDIAN_H
#include <stdint.h>

/**
 * @file
 *
 * @brief 字节序处理相关的函数集合
 */

/**
 * @brief         从网络序的 8 位字节流中读取出一个本地序的无符号整数
 *
 * 此函数不检查输入的合法性，请在使用前自行检查：
 * - 指向字节流的指针不能为 NULL
 * - 读取的整数长度不能为 0, 不能超过 uintmax_t 的长度
 *
 * @param[in]     net_bytes     网络字节流指针
 * @param[in]     size          读取的无符号整形的长度(sizeof)
 *
 * @return        返回网络新字节流的 size 长度代表的无符号整数值
 *
 */
uintmax_t bytes2uint(const uint8_t *net_bytes, unsigned size);

/**
 * @brief         将一个无符号整数填充到网络序的字节流中。
 *
 * 以网络序将一个无符号整数填入一个 8 位字节数组中，当字节流的存储空间不足时，
 * 仅保留无无符号整数的低字节的部分。
 *
 * @param[in]     uint          无符号整数
 * @param[out]    net_bytes     要填充的网络 8 位字节数组
 * @param[in]     size          要填充的网络 8 位字节数组的存储空间大小
 *
 * @return        已保存入 8 位字节数组中的部分所代表的数字，
 * 可以比较 uint 与返回值，以确定网络 8 位字节数组是否已完整存储了 uint。
 */
uintmax_t uint2bytes(uintmax_t uint, uint8_t *net_bytes, unsigned size);

#endif
