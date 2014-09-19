const color_t ground_palette[69] = {0xffff, 0x3c00, 0x5e40, 0x5e60, 0x55e0, 0x4d61, 0x4d01, 0x4d41, 0x55c0, 0x5620, 0x5e80, 0x5e20, 0x5581, 0x4ca2, 0x4403, 0x43e3, 0x4482, 0x5600, 0x5ea0, 0x4d21, 0x3b44, 0x3b24, 0x55a0, 0x4cc1, 0x4ce1, 0x4422, 0x4cc2, 0x4442, 0x4402, 0x5561, 0x3b63, 0x3b43, 0x3ba3, 0x32e4, 0x3b04, 0x3bc3, 0x4d02, 0x4443, 0x3b64, 0x3b83, 0x4462, 0x55a1, 0x4463, 0x4423, 0x3304, 0x3be3, 0x32a4, 0x3aa4, 0x3ac4, 0x3a03, 0x3a23, 0x3a43, 0x3a42, 0x3981, 0x41a1, 0x4120, 0x40e0, 0x40c0, 0x38a0, 0x38c0, 0x30a0, 0x2880, 0x3080, 0x48e0, 0x4100, 0x28a0, 0x4900, 0x30c0, 0x38e0};

const unsigned char ground[1024] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,1,1,2,2,2,2,3,3,3,2,4,5,6,6,7,8,9,2,3,10,3,2,4,5,6,6,7,8,1,1,0,
	0,1,1,2,11,2,2,3,10,10,2,12,13,14,15,16,7,17,3,18,18,10,2,12,13,14,15,16,7,1,1,0,
	0,1,1,2,2,2,2,3,10,10,9,19,14,20,21,15,6,4,3,18,18,10,9,19,14,20,21,15,6,1,1,0,
	0,1,1,2,2,2,2,2,2,9,22,23,15,21,20,14,6,17,3,10,3,9,22,23,15,21,20,14,6,1,1,0,
	0,1,1,3,10,3,2,17,22,7,24,16,25,14,25,23,22,2,3,9,8,7,24,16,25,14,25,26,12,1,1,0,
	0,1,1,10,18,10,2,22,24,27,28,27,13,6,29,8,2,10,2,22,24,27,28,27,13,6,5,8,17,1,1,0,
	0,1,1,10,18,10,9,19,25,30,31,14,24,8,2,10,18,10,9,19,25,30,31,14,24,8,2,3,3,1,1,0,
	0,1,1,9,9,9,22,26,32,33,34,35,24,8,2,3,3,9,22,26,32,33,34,35,24,8,2,2,9,1,1,0,
	0,1,1,7,5,7,36,37,38,33,33,39,40,19,12,41,12,5,36,37,38,33,33,39,40,19,12,12,5,1,1,0,
	0,1,1,37,42,37,43,35,20,44,44,38,45,37,40,16,40,37,43,35,20,44,44,38,45,37,40,40,42,1,1,0,
	0,1,1,38,38,38,20,20,21,44,44,21,20,38,38,38,38,38,20,20,21,44,44,21,20,38,38,38,38,1,1,0,
	0,1,1,46,46,46,47,48,48,48,48,48,48,47,46,46,46,46,47,48,48,48,48,48,48,47,46,46,46,1,1,0,
	0,1,1,49,49,49,49,50,51,52,52,51,50,49,49,49,49,49,49,50,51,52,52,51,50,49,49,49,49,1,1,0,
	0,1,1,53,53,53,53,54,54,54,54,54,54,53,53,53,53,53,53,54,54,54,54,54,54,53,53,53,53,1,1,0,
	0,1,1,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,1,1,0,
	0,1,1,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,1,1,0,
	0,1,1,56,56,56,57,57,58,58,58,59,57,57,56,56,56,56,57,57,58,58,58,59,57,57,56,56,56,1,1,0,
	0,1,1,56,56,56,56,59,60,61,62,60,59,56,63,63,63,56,56,59,60,61,62,60,59,56,63,63,56,1,1,0,
	0,1,1,64,64,64,56,59,65,61,61,60,59,56,64,66,66,64,56,59,65,61,61,60,59,56,64,64,64,1,1,0,
	0,1,1,64,64,64,56,59,65,61,61,65,67,68,64,64,64,64,56,59,65,61,61,65,67,68,56,64,64,1,1,0,
	0,1,1,64,64,64,56,68,67,60,65,60,67,67,59,68,56,64,56,68,67,60,65,60,67,67,59,68,56,1,1,0,
	0,1,1,64,64,64,64,56,68,59,67,67,60,65,60,67,68,56,64,56,68,59,67,67,60,65,60,67,68,1,1,0,
	0,1,1,64,64,64,64,64,64,56,68,67,65,61,61,65,59,56,64,64,64,64,68,67,65,61,61,65,59,1,1,0,
	0,1,1,64,64,64,64,64,64,64,56,59,60,61,61,65,59,56,64,66,66,64,56,59,60,61,61,65,59,1,1,0,
	0,1,1,64,64,64,64,64,64,64,64,68,67,65,65,67,68,56,64,64,66,64,64,68,67,65,65,67,68,1,1,0,
	0,1,1,64,64,64,64,64,64,64,64,56,68,59,59,68,68,56,64,64,64,64,64,56,68,59,59,68,68,1,1,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

const color_t grass_palette[28] = {0xffff, 0x3c00, 0x5e40, 0x5e60, 0x55e0, 0x4d61, 0x4d01, 0x4d41, 0x55c0, 0x5620, 0x5e80, 0x5e20, 0x5581, 0x4ca2, 0x4403, 0x43e3, 0x4482, 0x5600, 0x5ea0, 0x4d21, 0x3b44, 0x3b24, 0x55a0, 0x4cc1, 0x43c3, 0x4462, 0x5561, 0x5580};

const unsigned char grass[1024] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,1,1,2,2,2,2,3,3,3,2,4,5,6,6,7,8,9,2,3,10,3,2,4,5,6,6,7,8,1,1,0,
	0,1,1,2,11,2,2,3,10,10,2,12,13,14,15,16,7,17,3,18,18,10,2,12,13,14,15,16,7,1,1,0,
	0,1,1,2,2,2,2,3,10,10,9,19,14,20,21,15,6,4,3,18,18,10,9,19,14,20,21,15,6,1,1,0,
	0,1,1,2,2,2,2,2,2,9,22,23,24,21,20,14,6,4,3,10,3,9,22,23,24,21,20,14,6,1,1,0,
	0,1,1,2,2,2,9,4,12,19,23,25,14,24,14,13,26,17,2,17,27,19,23,25,14,24,14,13,5,1,1,0,
	0,1,1,2,3,3,17,5,13,14,24,14,25,23,19,27,17,2,17,26,13,14,24,14,25,23,19,12,4,1,1,0,
	0,1,1,3,3,3,4,6,14,20,21,24,23,22,9,3,10,3,4,6,14,20,21,24,23,22,9,2,2,1,1,0,
	0,1,1,3,3,3,4,6,15,21,20,14,19,9,10,18,18,3,4,6,15,21,20,14,19,9,10,10,3,1,1,0,
	0,1,1,2,3,3,17,7,16,15,14,13,12,2,10,18,18,3,17,7,16,15,14,13,12,2,10,10,3,1,1,0,
	0,1,1,2,2,2,9,8,7,6,6,5,4,2,3,10,3,2,9,8,7,6,6,5,4,2,3,3,3,1,1,0,
	0,1,1,2,2,2,11,9,17,4,4,17,9,2,2,2,2,2,11,9,17,4,4,17,9,2,2,2,2,1,1,0,
	0,1,1,2,2,2,2,2,3,3,3,3,2,2,2,11,11,2,2,2,3,3,3,3,2,2,2,2,2,1,1,0,
	0,1,1,11,11,11,2,3,10,18,18,10,3,2,11,11,11,11,2,3,10,18,18,10,3,2,11,11,11,1,1,0,
	0,1,1,11,11,11,2,3,10,18,18,10,3,2,11,11,11,11,2,3,10,18,18,10,3,2,11,11,11,1,1,0,
	0,1,1,2,2,2,2,2,3,3,3,3,2,2,2,11,11,2,2,2,3,3,3,3,2,2,2,2,2,1,1,0,
	0,1,1,2,2,2,11,9,17,4,4,17,9,2,2,2,2,2,11,9,17,4,4,17,9,2,2,2,2,1,1,0,
	0,1,1,2,2,2,9,8,7,6,6,5,4,2,3,10,3,2,9,8,7,6,6,5,4,2,3,3,3,1,1,0,
	0,1,1,2,3,3,17,7,16,15,14,13,12,2,10,18,18,3,17,7,16,15,14,13,12,2,10,10,3,1,1,0,
	0,1,1,3,3,3,4,6,15,21,20,14,19,9,10,18,18,3,4,6,15,21,20,14,19,9,10,10,3,1,1,0,
	0,1,1,3,3,3,4,6,14,20,21,24,23,22,9,3,10,3,4,6,14,20,21,24,23,22,9,2,2,1,1,0,
	0,1,1,2,3,3,17,5,13,14,24,14,25,23,19,27,17,2,17,26,13,14,24,14,25,23,19,12,4,1,1,0,
	0,1,1,2,2,2,9,4,12,19,23,25,14,24,14,13,26,17,2,17,27,19,23,25,14,24,14,13,5,1,1,0,
	0,1,1,2,2,2,2,2,2,9,22,23,24,21,20,14,6,4,3,10,3,9,22,23,24,21,20,14,6,1,1,0,
	0,1,1,2,2,2,2,3,10,10,9,19,14,20,21,15,6,4,3,18,18,10,9,19,14,20,21,15,6,1,1,0,
	0,1,1,2,11,2,2,3,10,10,2,12,13,14,15,16,7,17,3,18,18,10,2,12,13,14,15,16,7,1,1,0,
	0,1,1,2,2,2,2,3,3,3,2,4,5,6,6,7,8,9,2,3,10,3,2,4,5,6,6,7,8,1,1,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};


const color_t egg_palette[119] = {0xffff, 0x571f, 0x4f1f, 0x877f, 0x5f3f, 0x3f1f, 0x7f7f, 0x2eff, 0x5f5f, 0x3f3f, 0x2f1f, 0x1eff, 0x16ff, 0x0edf, 0x471f, 0x06df, 0x06bf, 0x671f, 0x2edf, 0x0e9f, 0x069f, 0xa73f, 0x66df, 0x367f, 0x1e5f, 0x163f, 0x165f, 0x9edf, 0x767f, 0x4e1f, 0x3dff, 0x35ff, 0xbebf, 0x9e7f, 0x861f, 0x6ddf, 0x5dbf, 0x5d9f, 0x65bf, 0xbe3f, 0xa5ff, 0x95bf, 0x857f, 0x7d5f, 0x755f, 0x7d7f, 0xd5ff, 0xc59f, 0xb55f, 0xad3f, 0x9d1f, 0xdd7f, 0xd4ff, 0xccdf, 0xc4df, 0xbcdf, 0xbcbf, 0xeddf, 0xe4df, 0xdc7f, 0xdc5f, 0xd47f, 0xd49f, 0xed9f, 0xe49f, 0xe41f, 0xe43f, 0xe45f, 0xed7f, 0xe47f, 0xe3ff, 0xec5f, 0xe3df, 0xdbff, 0xdc9f, 0xdc1f, 0xdc3f, 0xe5bf, 0xdcdf, 0xd45f, 0xd43f, 0xe5ff, 0xd51f, 0xccbf, 0xcc9f, 0xd57f, 0xcd1f, 0xc4ff, 0xbd5f, 0xa53f, 0xc63f, 0x85df, 0x6d9f, 0x659f, 0x5d7f, 0xbeff, 0x96bf, 0x665f, 0x3e3f, 0x261f, 0x25ff, 0x2e1f, 0x361f, 0x8f3f, 0x4eff, 0x16bf, 0x067f, 0x575f, 0x1f1f, 0x4f5f, 0x373f, 0x271f, 0x6f5f, 0x4f3f, 0x473f, 0xa79f, 0x8f7f, 0x7f5f, 0x673f};

const unsigned char egg[1024] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,3,4,2,5,5,2,4,3,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,6,4,5,7,7,7,7,5,4,6,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,8,9,10,11,12,13,13,12,11,10,9,8,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,14,11,13,13,15,15,16,16,15,15,13,13,11,14,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,17,18,19,20,20,20,20,20,20,20,20,20,20,19,18,17,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,21,22,23,24,25,26,24,24,24,24,24,24,26,25,24,23,22,21,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,27,28,29,30,31,30,30,30,30,30,30,30,30,31,30,29,28,27,0,0,0,0,0,0,0,
	0,0,0,0,0,0,32,33,34,35,36,37,36,38,38,38,38,38,38,36,37,36,35,34,33,32,0,0,0,0,0,0,
	0,0,0,0,0,0,39,40,41,42,43,44,43,45,45,45,45,45,45,43,44,43,42,41,40,39,0,0,0,0,0,0,
	0,0,0,0,0,46,47,48,49,50,50,50,50,50,50,50,50,50,50,50,50,50,50,49,48,47,46,0,0,0,0,0,
	0,0,0,0,0,51,52,53,54,55,56,56,56,55,55,55,55,55,55,56,56,56,55,54,53,52,51,0,0,0,0,0,
	0,0,0,0,57,58,59,60,59,61,62,62,62,62,62,62,62,62,62,62,62,62,61,59,60,59,58,57,0,0,0,0,
	0,0,0,0,63,64,65,65,66,67,67,67,67,67,67,67,67,67,67,67,67,67,67,66,65,65,64,63,0,0,0,0,
	0,0,0,0,68,69,70,70,65,71,71,71,71,71,71,71,71,71,71,71,71,71,71,65,70,70,69,68,0,0,0,0,
	0,0,0,0,68,67,70,72,65,71,71,71,71,71,71,71,71,71,71,71,71,71,71,65,72,70,67,68,0,0,0,0,
	0,0,0,0,68,69,73,73,65,67,69,69,69,69,69,69,69,69,69,69,69,69,67,65,73,73,69,68,0,0,0,0,
	0,0,0,0,63,74,75,75,76,59,59,59,59,59,59,59,59,59,59,59,59,59,59,76,75,75,74,63,0,0,0,0,
	0,0,0,0,77,78,79,80,79,61,62,62,62,62,62,62,62,62,62,62,62,62,61,79,80,79,78,77,0,0,0,0,
	0,0,0,0,81,82,83,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,83,82,81,0,0,0,0,
	0,0,0,0,0,85,86,87,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,87,86,85,0,0,0,0,0,
	0,0,0,0,0,46,47,88,49,89,50,50,50,50,50,50,50,50,50,50,50,50,89,49,88,47,46,0,0,0,0,0,
	0,0,0,0,0,0,90,40,91,92,93,94,93,92,92,92,92,92,92,93,94,93,92,91,40,90,0,0,0,0,0,0,
	0,0,0,0,0,0,95,96,97,98,99,100,101,101,102,102,102,102,101,101,100,99,98,97,96,95,0,0,0,0,0,0,
	0,0,0,0,0,0,0,103,104,105,106,106,106,20,19,19,19,19,20,106,106,106,105,104,103,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,107,108,15,15,15,15,15,15,15,15,15,15,15,15,108,107,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,109,110,111,111,111,108,108,108,108,111,111,111,110,109,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,6,112,8,113,114,114,114,114,113,8,112,6,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,115,116,117,112,118,118,112,117,116,115,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};