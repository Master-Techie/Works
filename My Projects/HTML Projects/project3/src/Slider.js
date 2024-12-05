import React, { useState, useEffect } from "react";
import "./Slider.css";

const Slider = () => {
  const slides = [
    {
      id: 1,
      image: "https://plus.unsplash.com/premium_photo-1732410903106-3379bbe6e9db?w=500&auto=format&fit=crop&q=60&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxmZWF0dXJlZC1waG90b3MtZmVlZHw2fHx8ZW58MHx8fHx8",
      title: "Promo 1",
      description: "This is the first promo description.",
    },
    {
      id: 2,
      image: "https://images.unsplash.com/photo-1732719812776-c043e861faf8?w=500&auto=format&fit=crop&q=60&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxmZWF0dXJlZC1waG90b3MtZmVlZHw3fHx8ZW58MHx8fHx8",
      title: "Promo 2",
      description: "This is the second promo description.",
    },
    {
      id: 3,
      image: "https://images.unsplash.com/photo-1732373558548-ccc9f9e83af0?w=500&auto=format&fit=crop&q=60&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxmZWF0dXJlZC1waG90b3MtZmVlZHwxNHx8fGVufDB8fHx8fA%3D%3D",
      title: "Promo 3",
      description: "This is the third promo description.",
    },
  ];

  const [currentIndex, setCurrentIndex] = useState(0);

  // Auto-slide every 3 seconds
  useEffect(() => {
    const timer = setInterval(() => {
      nextSlide();
    }, 3000);
    return () => clearInterval(timer);
  }, [currentIndex]);

  // Handlers
  const nextSlide = () => {
    setCurrentIndex((prev) => (prev === slides.length - 1 ? 0 : prev + 1));
  };

  const prevSlide = () => {
    setCurrentIndex((prev) => (prev === 0 ? slides.length - 1 : prev - 1));
  };

  const goToSlide = (index) => {
    setCurrentIndex(index);
  };

  return (
    <div className="slider">
      <div className="slider-container">
        {slides.map((slide, index) => (
          <div
            className={`slide ${index === currentIndex ? "active" : ""}`}
            key={slide.id}
            style={{ backgroundImage: `url(${slide.image})` }}
          >
            <div className="content">
              <h2>{slide.title}</h2>
              <p>{slide.description}</p>
            </div>
          </div>
        ))}
      </div>

      {/* Navigation Arrows */}
      <button className="arrow prev" onClick={prevSlide}>
        ❮
      </button>
      <button className="arrow next" onClick={nextSlide}>
        ❯
      </button>

      {/* Dots */}
      <div className="dots">
        {slides.map((_, index) => (
          <span
            key={index}
            className={`dot ${index === currentIndex ? "active" : ""}`}
            onClick={() => goToSlide(index)}
          ></span>
        ))}
      </div>
    </div>
  );
};

export default Slider;
