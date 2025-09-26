
return ((octet >> 4) | (octet << 4));


result = (result << 1) | (octet & 1);
octet = octet >> 1;
i--;

:
