import React, { useState, useEffect } from 'react';
import { createRoot } from 'react-dom/client';

function Toggle() {
  const [on, setOn] = useState(true);

  return (
      <button id="toggleButton" onClick={() => setOn(!on)}>{ on ? 'ON' : 'OFF' }</button>

  );
}

const container = document.getElementById('root');
const root = createRoot(container);
root.render(<Toggle />);