/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2016 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  $Id: sample1.c 711 2016-03-29 14:45:54Z ertl-hiro $
 */


#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"
#include "can.h"
#include "device_io.h"
#include <string.h>

/*
 *  割込みハンドラ
 */
#ifdef INTNO1

void intno1_isr(intptr_t exinf)
{
	intno1_clear();
}

#endif /* INTNO1 */

#ifdef CPUEXC1

void
cpuexc_handler(void *p_excinf)
{

}

#endif /* CPUEXC1 */

/*
 *  周期ハンドラ
 *
 *  HIGH_PRIORITY，MID_PRIORITY，LOW_PRIORITY の各優先度のレディキュー
 *  を回転させる．
 */
void cyclic_handler(intptr_t exinf)
{
}

/*
 *  アラームハンドラ
 *
 *  HIGH_PRIORITY，MID_PRIORITY，LOW_PRIORITY の各優先度のレディキュー
 *  を回転させる．
 */
void alarm_handler(intptr_t exinf)
{
}

/*
 *  例外処理タスク
 */
void exc_task(intptr_t exinf)
{
}

// 数値を文字列に変換する関数
void uint32_to_str(uint32_t num, char *str) {
    int i = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // 数値を逆順で文字列に変換
    while (num != 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    str[i] = '\0';

    // 文字列を反転
    int j = 0;
    char temp;
    for (j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}
#define SERIAL_OUT_ADDR		((volatile unsigned char*)0xFFFFFA07)

void test_print(const char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		*(SERIAL_OUT_ADDR) = str[i];
	}
}

#define EX_DEVICE_MEMORY_START  0x090F0000
#define EX_DEVICE_MEMORY_SIZE	(1U * 1024U) /* Bytes */

#define HAKO_SMAPLEDEV_TX_ADDR EX_DEVICE_MEMORY_START
#define HAKO_SMAPLEDEV_RX_ADDR (EX_DEVICE_MEMORY_START + 4U)
void timer_interrupt_handler(void)
{
	static int count = 1024;
	uint32 data = sil_rew_mem(HAKO_SMAPLEDEV_RX_ADDR);
	char data_str[12]; // uint32_t の最大桁数は10桁 + 終端文字
    uint32_to_str(data, data_str);
	test_print("<task1>: read data = ");
	test_print(data_str);
	test_print("\n");

    uint32_to_str((unsigned int)count, data_str);
	test_print("<task1> write data = ");
	test_print(data_str);
	test_print("\n");
	sil_wrw_mem(HAKO_SMAPLEDEV_TX_ADDR, (uint32)count);

	count++;
	return;
}

/*
 *  メインタスク
 */
void main_task(intptr_t exinf)
{
	syslog(LOG_NOTICE, "main_task waked up");
	while (1) {
		dly_tsk(1000);
	}
}

void task1(intptr_t exinf)
{
	syslog(LOG_NOTICE, "task1 waked up");
	while (1) {
		dly_tsk(1000000);
		timer_interrupt_handler();
	}
}
