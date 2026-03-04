import React from 'react';
import './LoadingLogo.css';

const LoadingLogo: React.FC = () => {
  return (
    <div className="loading-logo">
      {/* Background Z-shaped stripe */}
      <svg
        className="loading-logo__stripe"
        width="320"
        height="90"
        viewBox="0 0 320 90"
        aria-hidden="true"
      >
        <defs>
          <linearGradient id="stripeGradient" x1="0%" y1="0%" x2="100%" y2="0%">
            <stop offset="0%" stopColor="#F5BC47" />
            <stop offset="62%" stopColor="#A59F9F" />
            <stop offset="100%" stopColor="#918989" />
          </linearGradient>
        </defs>
        {/* Z path: top-right to top-left, diagonal to bottom-right, bottom-right to bottom-left */}
        <path
          className="loading-logo__stripe-path"
          d="M 260 18 L 80 18 L 240 72 L 60 72"
        />
      </svg>

      {/* Main text row */}
      <div className="loading-logo__text-row">
        <span className="loading-logo__letter-f">F</span>
        <span className="loading-logo__lo" data-text="lo">lo</span>
        <span className="loading-logo__letter-w">W</span>
        <span className="loading-logo__ealth" data-text="ealth">ealth</span>
      </div>

      {/* Tagline */}
      <p className="loading-logo__tagline">
        Flowing awareness is your real security
      </p>
    </div>
  );
};

export default LoadingLogo;
