#ifndef MATH_RADIAN_H
#define MATH_RADIAN_H

namespace Math
{
    class Degree;
    class Radian final
    {
        public:
            Radian() = default;
            Radian(const float radian);
            explicit Radian(const Degree &degree);
            float GetRadians() const noexcept;
            void SetRadians(const float radians) noexcept;

            template <class T>
            T operator * (const T param) const;
        private:
            float m_Radians = 0;
            friend class Degree;
            friend float cos(const Radian &rad);
            friend float sin(const Radian &rad);
    };


    template <class T>
    T Radian::operator * (const T param) const
    {
        return m_Radians * param;
    }
}
#endif // MATH_RADIAN_H
