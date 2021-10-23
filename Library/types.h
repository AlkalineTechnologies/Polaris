namespace Polaris {
    struct Vector{
        struct Vector2 {
            float X, Y;
            Vector2(float _x, float _y){X = _x; Y = _y;}
            Vector2 operator+=(Vector2 add){
                return  Vector2(X+add.X, Y+add.Y);
            }
            Vector2 operator-=(Vector2 add){
                return  Vector2(X-add.X, Y-add.Y);
            }
        };
        struct Vector3 {
            float X, Y, Z;
            Vector3(float _x, float _y, float _z){X = _x; Y = _y; Z = _z;};
            Vector3 operator+=(Vector3 add){
                return Vector3(X+add.X,Y+add.Y, Z+add.Z);
            }
            Vector3 operator-=(Vector3 add){
                return Vector3(X-add.X,Y-add.Y, Z-add.Z);
            }
        };
    };
}
