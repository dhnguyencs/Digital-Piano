#pragma once
#include "olcPixelGameEngineGL.h"
#include "tsf.h"
#include "minisdl_audio.h"
#include "MidiFile.h"
#include "RtMidi.h"
#include "Options.h"
#include "DigitalPiano.h"
#include "MAPPER.h"
#include "Keys.h"
#include <iostream>
#include <chrono>
#include <signal.h>
#include <thread>
#include <map>
#include <unordered_map>
#include <queue>
#include <mutex>

template <class TYPE>
struct vector3d {
    TYPE                x, y, z;
    vector3d            (TYPE x, TYPE y, TYPE z)    { this->x = x; this->y = y; this->z = z; }
    vector3d            (TYPE xyz)                  { this->x = xyz; this->y = xyz; this->z = xyz; }
    vector3d            ()                          { this->x = 0; this->y = 0; this->z = 0; }

    vector3d operator + (vector3d const& obj)       { vector3d result; result.x = x + obj.x; result.y = y + obj.y; result.z = z + obj.z; return result; }
    vector3d operator - (vector3d const& obj)       { vector3d result; result.x = x - obj.x; result.y = y - obj.y; result.z = z - obj.z; return result; }
    vector3d operator * (vector3d const& obj)       { vector3d result; result.x = x * obj.x; result.y = y * obj.y; result.z = z * obj.z; return result; }
    vector3d operator / (vector3d const& obj)       { vector3d result; result.x = x / obj.x; result.y = y / obj.y; result.z = z / obj.z; return result; }
    void setAll         (TYPE xyz)                  { this->x = xyz; this->y = xyz; this->z = xyz; }

    template<class Other> vector3d<Other> cast_to() { return vector3d<Other>{ static_cast<Other>(x), static_cast<Other>(y), static_cast<Other>(z) }; };
};

typedef vector3d<int>         vector3i;
typedef vector3d<float>       vector3f;
typedef vector3d<long double> vector3Ld;
typedef vector3d<uint16_t>    vector3Uint16t;