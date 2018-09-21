#pragma once

#define swap(a, b) typeof(a) __tmp = (a); (a) = (b); (b) = __tmp;
