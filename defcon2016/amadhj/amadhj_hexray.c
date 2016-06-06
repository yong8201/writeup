#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <klee/klee.h>

#define __int64 long long
#define __int8 char
#define __int16 short
#define _DWORD unsigned long

__int64  sub_4010B9(__int64 a1, __int64 a2)
{
	return a1 ^ a2;
}

unsigned __int64 sub_401259(unsigned __int64 a1, char a2, char a3)
{
	return ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a2) << 8 * a3) | ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a3) << 8 * a2) | ~(255LL << 8 * a2) & ~(255LL << 8 * a3) & a1;
}

unsigned __int64  sub_4010D2(unsigned __int64 a1, char a2)
{
	unsigned __int64 result; // rax@2

	if ( a2 & 0x3F )
		result = (a1 << (a2 & 0x3F)) | (a1 >> (64 - (a2 & 0x3Fu)));
	else
		result = a1;
	return result;
}

unsigned __int64  sub_40113E(unsigned __int64 a1, char a2)
{
	unsigned __int64 result; // rax@2

	if ( a2 & 0x3F )
		result = (a1 << (64 - (a2 & 0x3Fu))) | (a1 >> (a2 & 0x3F));
	else
		result = a1;
	return result;
}

unsigned __int64  sub_401326(__int64 a1)
{
	return (a1 << 56) ^ a1 & 0xFF00000000000000LL | ((unsigned __int64)((unsigned __int16)a1 & 0xFF00) >> 8) ^ (unsigned __int8)a1 | ((unsigned __int64)(a1 & 0xFF0000) >> 8) ^ (unsigned __int16)a1 & 0xFF00 | ((unsigned __int64)((unsigned int)a1 & 0xFF000000) >> 8) ^ a1 & 0xFF0000 | ((a1 & 0xFF00000000uLL) >> 8) ^ (unsigned int)a1 & 0xFF000000 | ((a1 & 0xFF0000000000uLL) >> 8) ^ a1 & 0xFF00000000LL | ((a1 & 0xFF000000000000uLL) >> 8) ^ a1 & 0xFF0000000000LL | ((a1 & 0xFF00000000000000LL) >> 8) ^ a1 & 0xFF000000000000LL;
}

unsigned __int64  sub_4011AA(__int64 a1)
{
	return ((a1 & 0xFF00000000000000LL) >> 8) | ((a1 & 0xFF000000000000uLL) >> 40) | ((a1 & 0xFF0000000000uLL) >> 40) | ((a1 & 0xFF00000000uLL) >> 16) | ((unsigned __int64)((unsigned int)a1 & 0xFF000000) << 16) | ((unsigned __int64)(a1 & 0xFF0000) << 40) | ((unsigned __int64)((unsigned __int16)a1 & 0xFF00) << 24) | (unsigned int)((_DWORD)a1 << 24);
}


__int64  first(__int64 a1)
{
	__int64 v1; // rax@1
	__int64 v2; // rax@1
	__int64 v3; // rax@1
	__int64 v4; // rax@1
	__int64 v5; // rax@1
	__int64 v6; // rax@1
	unsigned __int64 v7; // rax@1
	unsigned __int64 v8; // rax@1
	__int64 v9; // rax@1
	unsigned __int64 v10; // rax@1
	unsigned __int64 v11; // rax@1
	unsigned __int64 v12; // rax@1
	__int64 v13; // rax@1
	__int64 v14; // rax@1
	__int64 v15; // rax@1
	unsigned __int64 v16; // rax@1
	__int64 v17; // rax@1
	__int64 v18; // rax@1
	unsigned __int64 v19; // rax@1
	__int64 v20; // rax@1
	__int64 v21; // rax@1
	__int64 v22; // rax@1
	__int64 v23; // rax@1
	__int64 v24; // rax@1
	__int64 v25; // rax@1
	unsigned __int64 v26; // rax@1
	unsigned __int64 v27; // rax@1
	unsigned __int64 v28; // rax@1
	unsigned __int64 v29; // rax@1
	unsigned __int64 v30; // rax@1
	__int64 v31; // rax@1
	__int64 v32; // rax@1
	__int64 v33; // rax@1
	unsigned __int64 v34; // rax@1
	unsigned __int64 v35; // rax@1
	__int64 v36; // rax@1
	__int64 v37; // rax@1
	__int64 v38; // rax@1
	__int64 v39; // rax@1
	__int64 v40; // rax@1
	__int64 v41; // rax@1
	unsigned __int64 v42; // rax@1
	__int64 v43; // rax@1
	unsigned __int64 v44; // rax@1
	unsigned __int64 v45; // rax@1
	__int64 v46; // rax@1
	__int64 v47; // rax@1
	__int64 v48; // rax@1
	__int64 v49; // rax@1
	unsigned __int64 v50; // rax@1
	unsigned __int64 v51; // rax@1
	__int64 v52; // rax@1
	__int64 v53; // rax@1
	__int64 v54; // rax@1
	__int64 v55; // rax@1
	unsigned __int64 v56; // rax@1
	__int64 v57; // rax@1

	v1 = sub_4010B9(a1, 3861390726976975706LL);
	v2 = sub_401259(v1, 2, 0);
	v3 = sub_4010B9(v2, -8503447668707217935LL);
	v4 = sub_4010B9(v3, -1588909695441795222LL);
	v5 = sub_401259(v4, 2, 3);
	v6 = sub_4010B9(v5, -4772405561947105562LL);
	v7 = sub_4010D2(v6, 16);
	v8 = sub_4010D2(v7, 35);
	v9 = sub_40113E(v8, 19LL);
	v10 = sub_401326(v9);
	v11 = sub_4010D2(v10, 36);
	v12 = sub_40113E(v11, 40LL);
	v13 = sub_401259(v12, 1, 0);
	v14 = sub_4010B9(v13, 6765015749217278743LL);
	v15 = sub_4011AA(v14);
	v16 = sub_4011AA(v15);
	v17 = sub_401259(v16, 2, 1);
	v18 = sub_4010B9(v17, 7686949068708848117LL);
	v19 = sub_401259(v18, 3, 0);
	v20 = sub_4011AA(v19);
	v21 = sub_4010B9(v20, 6401935715922169987LL);
	v22 = sub_40113E(v21, 22LL);
	v23 = sub_401326(v22);
	v24 = sub_4010B9(v23, 5166993816397978483LL);
	v25 = sub_401326(v24);
	v26 = sub_401326(v25);
	v27 = sub_401259(v26, 6, 5);
	v28 = sub_4010D2(v27, 59);
	v29 = sub_401259(v28, 5, 2);
	v30 = sub_401259(v29, 2, 3);
	v31 = sub_4010D2(v30, 12);
	v32 = sub_4010B9(v31, -5970312406604821737LL);
	v33 = sub_4010B9(v32, 5234710379464860866LL);
	v34 = sub_4010D2(v33, 6);
	v35 = sub_401259(v34, 6, 5);
	v36 = sub_40113E(v35, 11LL);
	v37 = sub_4011AA(v36);
	v38 = sub_4010B9(v37, -8749537658492994378LL);
	v39 = sub_4011AA(v38);
	v40 = sub_40113E(v39, 2LL);
	v41 = sub_4010B9(v40, 4649309708712362587LL);
	v42 = sub_4010D2(v41, 35);
	v43 = sub_4010D2(v42, 9);
	v44 = sub_401326(v43);
	v45 = sub_4010D2(v44, 7);
	v46 = sub_4010D2(v45, 38);
	v47 = sub_401326(v46);
	v48 = sub_4010B9(v47, -2381604702099911141LL);
	v49 = sub_4011AA(v48);
	v50 = sub_4011AA(v49);
	v51 = sub_401259(v50, 2, 7);
	v52 = sub_40113E(v51, 51LL);
	v53 = sub_4011AA(v52);
	v54 = sub_40113E(v53, 19LL);
	v55 = sub_4010B9(v54, -7647594470186881503LL);
	v56 = sub_401326(v55);
	v57 = sub_4011AA(v56);
	return sub_40113E(v57, 16LL);
}

unsigned __int64  second(unsigned __int64 a1)
{
	unsigned __int64 v1; // rax@1
	unsigned __int64 v2; // rax@1
	unsigned __int64 v3; // rax@1
	__int64 v4; // rax@1
	unsigned __int64 v5; // rax@1
	unsigned __int64 v6; // rax@1
	__int64 v7; // rax@1
	__int64 v8; // rax@1
	unsigned __int64 v9; // rax@1
	unsigned __int64 v10; // rax@1
	unsigned __int64 v11; // rax@1
	__int64 v12; // rax@1
	unsigned __int64 v13; // rax@1
	unsigned __int64 v14; // rax@1
	unsigned __int64 v15; // rax@1
	unsigned __int64 v16; // rax@1
	__int64 v17; // rax@1
	__int64 v18; // rax@1
	unsigned __int64 v19; // rax@1
	unsigned __int64 v20; // rax@1
	unsigned __int64 v21; // rax@1
	unsigned __int64 v22; // rax@1
	unsigned __int64 v23; // rax@1
	unsigned __int64 v24; // rax@1
	__int64 v25; // rax@1
	unsigned __int64 v26; // rax@1
	__int64 v27; // rax@1
	unsigned __int64 v28; // rax@1
	__int64 v29; // rax@1
	__int64 v30; // rax@1
	__int64 v31; // rax@1
	unsigned __int64 v32; // rax@1
	unsigned __int64 v33; // rax@1
	unsigned __int64 v34; // rax@1
	__int64 v35; // rax@1
	__int64 v36; // rax@1
	unsigned __int64 v37; // rax@1
	unsigned __int64 v38; // rax@1
	unsigned __int64 v39; // rax@1
	unsigned __int64 v40; // rax@1
	unsigned __int64 v41; // rax@1
	unsigned __int64 v42; // rax@1
	__int64 v43; // rax@1
	__int64 v44; // rax@1
	unsigned __int64 v45; // rax@1
	unsigned __int64 v46; // rax@1
	unsigned __int64 v47; // rax@1
	unsigned __int64 v48; // rax@1
	__int64 v49; // rax@1
	__int64 v50; // rax@1
	unsigned __int64 v51; // rax@1

	v1 = sub_4010D2(a1, 22);
	v2 = sub_4011AA(v1);
	v3 = sub_401259(v2, 4, 1);
	v4 = sub_4011AA(v3);
	v5 = sub_401326(v4);
	v6 = sub_4010D2(v5, 35);
	v7 = sub_401259(v6, 2, 6);
	v8 = sub_4010B9(v7, -9175545138341720086LL);
	v9 = sub_4010D2(v8, 3);
	v10 = sub_401259(v9, 0, 1);
	v11 = sub_401259(v10, 1, 2);
	v12 = sub_4011AA(v11);
	v13 = sub_401326(v12);
	v14 = sub_401259(v13, 5, 1);
	v15 = sub_40113E(v14, 24LL);
	v16 = sub_4010D2(v15, 39);
	v17 = sub_401259(v16, 2, 4);
	v18 = sub_4010B9(v17, 7462025471038891063LL);
	v19 = sub_401259(v18, 4, 3);
	v20 = sub_401259(v19, 0, 7);
	v21 = sub_4010D2(v20, 62);
	v22 = sub_4011AA(v21);
	v23 = sub_401259(v22, 7, 6);
	v24 = sub_401259(v23, 2, 6);
	v25 = sub_4011AA(v24);
	v26 = sub_401326(v25);
	v27 = sub_401259(v26, 5, 2);
	v28 = sub_401326(v27);
	v29 = sub_401259(v28, 1, 7);
	v30 = sub_4010B9(v29, 4749710960471120103LL);
	v31 = sub_4011AA(v30);
	v32 = sub_401326(v31);
	v33 = sub_401259(v32, 1, 4);
	v34 = sub_4010D2(v33, 10);
	v35 = sub_4011AA(v34);
	v36 = sub_4011AA(v35);
	v37 = sub_40113E(v36, 24LL);
	v38 = sub_401259(v37, 0, 4);
	v39 = sub_40113E(v38, 61LL);
	v40 = sub_401259(v39, 3, 4);
	v41 = sub_40113E(v40, 35LL);
	v42 = sub_4010D2(v41, 55);
	v43 = sub_4010D2(v42, 34);
	v44 = sub_401326(v43);
	v45 = sub_401326(v44);
	v46 = sub_40113E(v45, 23LL);
	v47 = sub_4010D2(v46, 59);
	v48 = sub_40113E(v47, 20LL);
	v49 = sub_4010D2(v48, 28);
	v50 = sub_4010B9(v49, -4439254868560369715LL);
	v51 = sub_401326(v50);
	return sub_40113E(v51, 13LL);
}



unsigned __int64  third(unsigned __int64 a1)
{
	unsigned __int64 v1; // rax@1
	unsigned __int64 v2; // rax@1
	unsigned __int64 v3; // rax@1
	unsigned __int64 v4; // rax@1
	__int64 v5; // rax@1
	__int64 v6; // rax@1
	unsigned __int64 v7; // rax@1
	__int64 v8; // rax@1
	unsigned __int64 v9; // rax@1
	unsigned __int64 v10; // rax@1
	__int64 v11; // rax@1
	__int64 v12; // rax@1
	__int64 v13; // rax@1
	unsigned __int64 v14; // rax@1
	__int64 v15; // rax@1
	unsigned __int64 v16; // rax@1
	unsigned __int64 v17; // rax@1
	__int64 v18; // rax@1
	unsigned __int64 v19; // rax@1
	__int64 v20; // rax@1
	unsigned __int64 v21; // rax@1
	unsigned __int64 v22; // rax@1
	__int64 v23; // rax@1
	__int64 v24; // rax@1
	unsigned __int64 v25; // rax@1
	unsigned __int64 v26; // rax@1
	unsigned __int64 v27; // rax@1
	__int64 v28; // rax@1
	__int64 v29; // rax@1
	unsigned __int64 v30; // rax@1
	unsigned __int64 v31; // rax@1
	unsigned __int64 v32; // rax@1
	__int64 v33; // rax@1
	__int64 v34; // rax@1
	__int64 v35; // rax@1
	__int64 v36; // rax@1
	__int64 v37; // rax@1
	unsigned __int64 v38; // rax@1
	unsigned __int64 v39; // rax@1
	unsigned __int64 v40; // rax@1
	__int64 v41; // rax@1
	__int64 v42; // rax@1
	__int64 v43; // rax@1
	__int64 v44; // rax@1
	__int64 v45; // rax@1
	__int64 v46; // rax@1
	unsigned __int64 v47; // rax@1
	__int64 v48; // rax@1
	unsigned __int64 v49; // rax@1
	__int64 v50; // rax@1
	__int64 v51; // rax@1

	v1 = sub_4010D2(a1, 18);
	v2 = sub_4010D2(v1, 29);
	v3 = sub_401259(v2, 5, 3);
	v4 = sub_401259(v3, 0, 7);
	v5 = sub_4010D2(v4, 18);
	v6 = sub_4010B9(v5, -3914929572723803987LL);
	v7 = sub_40113E(v6, 33LL);
	v8 = sub_401259(v7, 0, 4);
	v9 = sub_401326(v8);
	v10 = sub_401259(v9, 6, 2);
	v11 = sub_40113E(v10, 13LL);
	v12 = sub_40113E(v11, 20LL);
	v13 = sub_4010B9(v12, 6368261268581873766LL);
	v14 = sub_401326(v13);
	v15 = sub_4011AA(v14);
	v16 = sub_40113E(v15, 46LL);
	v17 = sub_401259(v16, 2, 3);
	v18 = sub_40113E(v17, 44LL);
	v19 = sub_40113E(v18, 3LL);
	v20 = sub_401259(v19, 4, 3);
	v21 = sub_401326(v20);
	v22 = sub_401259(v21, 7, 6);
	v23 = sub_40113E(v22, 59LL);
	v24 = sub_40113E(v23, 38LL);
	v25 = sub_4011AA(v24);
	v26 = sub_401259(v25, 1, 5);
	v27 = sub_4011AA(v26);
	v28 = sub_4010D2(v27, 27);
	v29 = sub_4010B9(v28, -4695715466604734865LL);
	v30 = sub_40113E(v29, 14LL);
	v31 = sub_4010D2(v30, 7);
	v32 = sub_4010D2(v31, 18);
	v33 = sub_4010D2(v32, 57);
	v34 = sub_4010B9(v33, -5457193149446634725LL);
	v35 = sub_4010B9(v34, 929788566303591270LL);
	v36 = sub_4010B9(v35, -7732292935714115039LL);
	v37 = sub_4010B9(v36, -8809338591802114998LL);
	v38 = sub_401259(v37, 5, 1);
	v39 = sub_4010D2(v38, 20);
	v40 = sub_4010D2(v39, 24);
	v41 = sub_40113E(v40, 46LL);
	v42 = sub_40113E(v41, 13LL);
	v43 = sub_4010B9(v42, -3936607641516927115LL);
	v44 = sub_4010D2(v43, 7);
	v45 = sub_4010B9(v44, 641209893495219690LL);
	v46 = sub_4010B9(v45, 6473287570272602621LL);
	v47 = sub_401326(v46);
	v48 = sub_401259(v47, 4, 7);
	v49 = sub_401326(v48);
	v50 = sub_40113E(v49, 22LL);
	v51 = sub_40113E(v50, 50LL);
	return sub_401326(v51);
}

unsigned __int64  fourth(__int64 a1)
{
	unsigned __int64 v1; // rax@1
	unsigned __int64 v2; // rax@1
	unsigned __int64 v3; // rax@1
	__int64 v4; // rax@1
	__int64 v5; // rax@1
	unsigned __int64 v6; // rax@1
	__int64 v7; // rax@1
	__int64 v8; // rax@1
	__int64 v9; // rax@1
	unsigned __int64 v10; // rax@1
	__int64 v11; // rax@1
	unsigned __int64 v12; // rax@1
	unsigned __int64 v13; // rax@1
	__int64 v14; // rax@1
	__int64 v15; // rax@1
	__int64 v16; // rax@1
	__int64 v17; // rax@1
	__int64 v18; // rax@1
	__int64 v19; // rax@1
	__int64 v20; // rax@1
	__int64 v21; // rax@1
	__int64 v22; // rax@1
	__int64 v23; // rax@1
	__int64 v24; // rax@1
	__int64 v25; // rax@1
	unsigned __int64 v26; // rax@1
	unsigned __int64 v27; // rax@1
	__int64 v28; // rax@1
	unsigned __int64 v29; // rax@1
	__int64 v30; // rax@1
	__int64 v31; // rax@1
	unsigned __int64 v32; // rax@1
	unsigned __int64 v33; // rax@1
	__int64 v34; // rax@1
	__int64 v35; // rax@1
	__int64 v36; // rax@1
	__int64 v37; // rax@1
	__int64 v38; // rax@1
	unsigned __int64 v39; // rax@1
	unsigned __int64 v40; // rax@1
	__int64 v41; // rax@1
	unsigned __int64 v42; // rax@1
	unsigned __int64 v43; // rax@1
	__int64 v44; // rax@1
	__int64 v45; // rax@1
	__int64 v46; // rax@1
	__int64 v47; // rax@1
	unsigned __int64 v48; // rax@1
	unsigned __int64 v49; // rax@1
	__int64 v50; // rax@1
	unsigned __int64 v51; // rax@1
	__int64 v52; // rax@1

	v1 = sub_401259(a1, 1, 7);
	v2 = sub_4010D2(v1, 6);
	v3 = sub_401259(v2, 2, 5);
	v4 = sub_40113E(v3, 57LL);
	v5 = sub_4010B9(v4, 902179681853661902LL);
	v6 = sub_401259(v5, 5, 1);
	v7 = sub_4010D2(v6, 1);
	v8 = sub_401326(v7);
	v9 = sub_4010B9(v8, 6764338754798371998LL);
	v10 = sub_401326(v9);
	v11 = sub_4010D2(v10, 6);
	v12 = sub_401326(v11);
	v13 = sub_4010D2(v12, 33);
	v14 = sub_40113E(v13, 25LL);
	v15 = sub_401326(v14);
	v16 = sub_4010B9(v15, 762415417889401952LL);
	v17 = sub_401259(v16, 6, 2);
	v18 = sub_401326(v17);
	v19 = sub_4010B9(v18, -3724318961155856981LL);
	v20 = sub_4010B9(v19, -8646321147571282756LL);
	v21 = sub_401326(v20);
	v22 = sub_4010B9(v21, -8802313616937474543LL);
	v23 = sub_40113E(v22, 8LL);
	v24 = sub_40113E(v23, 43LL);
	v25 = sub_4010B9(v24, 7150187182015826299LL);
	v26 = sub_401259(v25, 3, 1);
	v27 = sub_401259(v26, 5, 7);
	v28 = sub_4011AA(v27);
	v29 = sub_401326(v28);
	v30 = sub_40113E(v29, 59LL);
	v31 = sub_40113E(v30, 10LL);
	v32 = sub_401326(v31);
	v33 = sub_401259(v32, 2, 1);
	v34 = sub_401259(v33, 7, 2);
	v35 = sub_401326(v34);
	v36 = sub_4010B9(v35, 7246290916701591349LL);
	v37 = sub_4010B9(v36, -243320396905423181LL);
	v38 = sub_4010B9(v37, -43605043069428557LL);
	v39 = sub_401259(v38, 2, 4);
	v40 = sub_401259(v39, 5, 4);
	v41 = sub_40113E(v40, 11LL);
	v42 = sub_401326(v41);
	v43 = sub_4010D2(v42, 39);
	v44 = sub_4011AA(v43);
	v45 = sub_401326(v44);
	v46 = sub_4010B9(v45, -4064264580452746468LL);
	v47 = sub_4011AA(v46);
	v48 = sub_401326(v47);
	v49 = sub_4010D2(v48, 35);
	v50 = sub_401259(v49, 3, 5);
	v51 = sub_401326(v50);
	v52 = sub_4011AA(v51);
	return sub_401326(v52);
}


int main() {
	unsigned long long v2, v3, v4;
	unsigned char key[32];

	klee_make_symbolic(key, sizeof(key), "key");
	for (int i = 0; i <= 31; ++i )
	{
		klee_assume(key[i] != 0x00); klee_assume(key[i] != 0x01); klee_assume(key[i] != 0x02); klee_assume(key[i] != 0x03); klee_assume(key[i] != 0x04); klee_assume(key[i] != 0x05); klee_assume(key[i] != 0x06); klee_assume(key[i] != 0x07); klee_assume(key[i] != 0x08); klee_assume(key[i] != 0x09); klee_assume(key[i] != 0x0a); klee_assume(key[i] != 0x0b); klee_assume(key[i] != 0x0c); klee_assume(key[i] != 0x0d); klee_assume(key[i] != 0x0e); klee_assume(key[i] != 0x0f); klee_assume(key[i] != 0x10); klee_assume(key[i] != 0x11); klee_assume(key[i] != 0x12); klee_assume(key[i] != 0x13); klee_assume(key[i] != 0x14); klee_assume(key[i] != 0x15); klee_assume(key[i] != 0x16); klee_assume(key[i] != 0x17); klee_assume(key[i] != 0x18); klee_assume(key[i] != 0x19); klee_assume(key[i] != 0x1a); klee_assume(key[i] != 0x1b); klee_assume(key[i] != 0x1c); klee_assume(key[i] != 0x1d); klee_assume(key[i] != 0x1e); klee_assume(key[i] != 0x1f); klee_assume(key[i] != 0x21); klee_assume(key[i] != 0x22); klee_assume(key[i] != 0x23); klee_assume(key[i] != 0x24); klee_assume(key[i] != 0x25); klee_assume(key[i] != 0x26); klee_assume(key[i] != 0x27); klee_assume(key[i] != 0x28); klee_assume(key[i] != 0x29); klee_assume(key[i] != 0x2a); klee_assume(key[i] != 0x2b); klee_assume(key[i] != 0x2c); klee_assume(key[i] != 0x2d); klee_assume(key[i] != 0x2e); klee_assume(key[i] != 0x2f); klee_assume(key[i] != 0x30); klee_assume(key[i] != 0x31); klee_assume(key[i] != 0x32); klee_assume(key[i] != 0x33); klee_assume(key[i] != 0x34); klee_assume(key[i] != 0x35); klee_assume(key[i] != 0x36); klee_assume(key[i] != 0x37); klee_assume(key[i] != 0x38); klee_assume(key[i] != 0x39); klee_assume(key[i] != 0x3a); klee_assume(key[i] != 0x3b); klee_assume(key[i] != 0x3c); klee_assume(key[i] != 0x3d); klee_assume(key[i] != 0x3e); klee_assume(key[i] != 0x3f); klee_assume(key[i] != 0x40); klee_assume(key[i] != 0x7b); klee_assume(key[i] != 0x7c); klee_assume(key[i] != 0x7d); klee_assume(key[i] != 0x7e); klee_assume(key[i] != 0x7f); klee_assume(key[i] != 0x80); klee_assume(key[i] != 0x81); klee_assume(key[i] != 0x82); klee_assume(key[i] != 0x83); klee_assume(key[i] != 0x84); klee_assume(key[i] != 0x85); klee_assume(key[i] != 0x86); klee_assume(key[i] != 0x87); klee_assume(key[i] != 0x88); klee_assume(key[i] != 0x89); klee_assume(key[i] != 0x8a); klee_assume(key[i] != 0x8b); klee_assume(key[i] != 0x8c); klee_assume(key[i] != 0x8d); klee_assume(key[i] != 0x8e); klee_assume(key[i] != 0x8f); klee_assume(key[i] != 0x90); klee_assume(key[i] != 0x91); klee_assume(key[i] != 0x92); klee_assume(key[i] != 0x93); klee_assume(key[i] != 0x94); klee_assume(key[i] != 0x95); klee_assume(key[i] != 0x96); klee_assume(key[i] != 0x97); klee_assume(key[i] != 0x98); klee_assume(key[i] != 0x99); klee_assume(key[i] != 0x9a); klee_assume(key[i] != 0x9b); klee_assume(key[i] != 0x9c); klee_assume(key[i] != 0x9d); klee_assume(key[i] != 0x9e); klee_assume(key[i] != 0x9f); klee_assume(key[i] != 0xa0); klee_assume(key[i] != 0xa1); klee_assume(key[i] != 0xa2); klee_assume(key[i] != 0xa3); klee_assume(key[i] != 0xa4); klee_assume(key[i] != 0xa5); klee_assume(key[i] != 0xa6); klee_assume(key[i] != 0xa7); klee_assume(key[i] != 0xa8); klee_assume(key[i] != 0xa9); klee_assume(key[i] != 0xaa); klee_assume(key[i] != 0xab); klee_assume(key[i] != 0xac); klee_assume(key[i] != 0xad); klee_assume(key[i] != 0xae); klee_assume(key[i] != 0xaf); klee_assume(key[i] != 0xb0); klee_assume(key[i] != 0xb1); klee_assume(key[i] != 0xb2); klee_assume(key[i] != 0xb3); klee_assume(key[i] != 0xb4); klee_assume(key[i] != 0xb5); klee_assume(key[i] != 0xb6); klee_assume(key[i] != 0xb7); klee_assume(key[i] != 0xb8); klee_assume(key[i] != 0xb9); klee_assume(key[i] != 0xba); klee_assume(key[i] != 0xbb); klee_assume(key[i] != 0xbc); klee_assume(key[i] != 0xbd); klee_assume(key[i] != 0xbe); klee_assume(key[i] != 0xbf); klee_assume(key[i] != 0xc0); klee_assume(key[i] != 0xc1); klee_assume(key[i] != 0xc2); klee_assume(key[i] != 0xc3); klee_assume(key[i] != 0xc4); klee_assume(key[i] != 0xc5); klee_assume(key[i] != 0xc6); klee_assume(key[i] != 0xc7); klee_assume(key[i] != 0xc8); klee_assume(key[i] != 0xc9); klee_assume(key[i] != 0xca); klee_assume(key[i] != 0xcb); klee_assume(key[i] != 0xcc); klee_assume(key[i] != 0xcd); klee_assume(key[i] != 0xce); klee_assume(key[i] != 0xcf); klee_assume(key[i] != 0xd0); klee_assume(key[i] != 0xd1); klee_assume(key[i] != 0xd2); klee_assume(key[i] != 0xd3); klee_assume(key[i] != 0xd4); klee_assume(key[i] != 0xd5); klee_assume(key[i] != 0xd6); klee_assume(key[i] != 0xd7); klee_assume(key[i] != 0xd8); klee_assume(key[i] != 0xd9); klee_assume(key[i] != 0xda); klee_assume(key[i] != 0xdb); klee_assume(key[i] != 0xdc); klee_assume(key[i] != 0xdd); klee_assume(key[i] != 0xde); klee_assume(key[i] != 0xdf); klee_assume(key[i] != 0xe0); klee_assume(key[i] != 0xe1); klee_assume(key[i] != 0xe2); klee_assume(key[i] != 0xe3); klee_assume(key[i] != 0xe4); klee_assume(key[i] != 0xe5); klee_assume(key[i] != 0xe6); klee_assume(key[i] != 0xe7); klee_assume(key[i] != 0xe8); klee_assume(key[i] != 0xe9); klee_assume(key[i] != 0xea); klee_assume(key[i] != 0xeb); klee_assume(key[i] != 0xec); klee_assume(key[i] != 0xed); klee_assume(key[i] != 0xee); klee_assume(key[i] != 0xef); klee_assume(key[i] != 0xf0); klee_assume(key[i] != 0xf1); klee_assume(key[i] != 0xf2); klee_assume(key[i] != 0xf3); klee_assume(key[i] != 0xf4); klee_assume(key[i] != 0xf5); klee_assume(key[i] != 0xf6); klee_assume(key[i] != 0xf7); klee_assume(key[i] != 0xf8); klee_assume(key[i] != 0xf9); klee_assume(key[i] != 0xfa); klee_assume(key[i] != 0xfb); klee_assume(key[i] != 0xfc); klee_assume(key[i] != 0xfd); klee_assume(key[i] != 0xfe); klee_assume(key[i] != 0xff); klee_assume(key[i] != ']'); klee_assume(key[i] != '\\'); klee_assume(key[i] != '^'); klee_assume(key[i] != '`'); klee_assume(key[i] != '[');

	}

	v2 = first(*(unsigned long long*)&key[0]);
	v3 = second(*(unsigned long long*)&key[8]);
	v4 = third(*(unsigned long long*)&key[16]);
	if ((fourth(*(unsigned long long*)&key[24]) ^ v4 ^ v2 ^ v3) == 0xB101124831C0110ALL)
	{
		klee_assert(0);
		return 1;
	}
	return 0;
}
