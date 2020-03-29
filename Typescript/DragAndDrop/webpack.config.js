const path = require('path');

module.exports = {
  entry: './src/app.ts',
  output: {
    filename: 'bundle.js', // This will be the single javascript file which will be produced in the end.
    path: path.resolve(__dirname, 'dist')
  },
  devtool: 'inline-source-map', // sourceMap: true 와 같이 브라우저에서 디버깅 쉽게 하도록 해줌.
  module: {
    rules: [
      {
        test: /\.ts$/,
        use: 'ts-loader',
        exclude: /node_modules/
      }
    ]
  },
  resolve: {
    extensions: ['.ts', '.js']
  }
};
